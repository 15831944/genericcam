///////////////////////////////////////////////////////////////////////////////
// Name               : Run.cpp
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 15.06.2011
// Copyright          : (C) 2011 Tobias Schaefer <tobiassch@users.sourceforge.net>
// Licence            : GNU General Public License version 3.0 (GPLv3)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////

#include "Run.h"

#include "Project.h"
#include "generator/GeneratorCollection.h"

#include "../icon/touchpoint.xpm"

#include <wx/log.h>
#include <GL/gl.h>
#include <float.h>
#include <assert.h>

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfRun)

Run::Run()
{
	selected = false;
//	modified = false;
	name = _T("Run #");
	refWorkpiece = -1;
//	toolbox.Empty();
	parent = NULL;
	textureID = 0;
	isOGLInit = false;
	touchoffHeight = 0.027;
	prevRun = -1;
	touchpoint = wxImage(touchpoint_xpm);
	touchpoint.SetAlphaColor(255, 255, 255);
	simulator.InsertMachine(&machine);
}

Run::Run(const Run& other)
{
	throw("'Run::Copy constructor' is unimplemented!");
}

Run& Run::operator=(const Run& other)
{
	if(&other == this) return *this;
	throw("'Run::operator=' is unimplemented!");
	return *this;
}

Run::~Run()
{
	if(isOGLInit) glDeleteTextures(1, &textureID);
	for(size_t i = 0; i < generators.GetCount(); i++)
		delete generators[i];
}

void Run::GenerateToolpaths(void)
{
	Update();
	for(size_t i = 0; i < generators.GetCount(); i++){
		assert(generators[i] != NULL);
		generators[i]->GenerateToolpath();
	}
}

void Run::Update(void)
{
	for(size_t i = 0; i < generators.GetCount(); i++){
		assert(generators[i] != NULL);
		generators[i]->parent = this;
	}
	simulator.InsertToolPath(this->GetSelectedToolpath());
	simulator.InsertWorkpiece(this->GetWorkpiece());
}

bool Run::SaveToolpaths(wxFileName fileName, ToolPath::Dialect dialect)
{
	ToolPath generated;
	for(size_t i = 0; i < generators.GetCount(); i++){
		assert(generators[i] != NULL);
		AffineTransformMatrix matrix;
		matrix.TranslateGlobal(generators[i]->area.xmin,
				generators[i]->area.ymin, generators[i]->area.zmin);
		ToolPath moved = generators[i]->toolpath;
		moved.ApplyTransformation(matrix);
		generated += moved;
	}

	// Move toolpath down by the touchoff height.
	AffineTransformMatrix matrix;
	matrix.TranslateGlobal(0, 0, -touchoffHeight);
	generated.ApplyTransformation(matrix);

	generated.CleanPath(0.0003);
	generated.DiffPath(0.0003);

	// TODO: Move the following lines into the toolpath generators.
	ToolPath startup;
	startup.positions.Add(GCodeBlock(_T("F3000 (Feedrate mm/min)")));
	startup.positions.Add(GCodeBlock(_T("T1 M6 (Tool 1, Select tool)")));
	startup.positions.Add(GCodeBlock(_T("S10000 (Spindle speed rpm)")));
	startup.positions.Add(GCodeBlock(_T("M3 (Start spindel)")));
	startup.positions.Add(
			GCodeBlock(
					_T("G4 P3 (wait for 3 seconds for the spindle to start)")));

	ToolPath temp = ToolPath::SafetyBlock() + startup + generated
			+ ToolPath::EndBlock();

	temp.Translate(dialect);

	setlocale(LC_ALL, "C"); // To get a 3.1415 instead 3,1415 or else on every computer.
	wxTextFile f;
	if(fileName.FileExists()){
		f.Open(fileName.GetFullPath());
		f.Clear();
	}else{
		f.Create(fileName.GetFullPath());
	}

	if(dialect == ToolPath::FanucM){
		// For the fanucm.exe g-code simulator.
		const wxTextFileType fileType = wxTextFileType_Dos;
		f.AddLine(_T("G21"), fileType);
		temp.CalculateMinMaxValues();
		f.AddLine(
				wxString::Format(_T("[billet x%g y%g z%g"),
						(temp.maxPosition.X - temp.minPosition.X) * 1000.0,
						(temp.maxPosition.Y - temp.minPosition.Y) * 1000.0,
						(-temp.minPosition.Z) * 1000.0 + 0.1), fileType);
		f.AddLine(
				wxString::Format(_T("[edgemove x%g y%g"),
						temp.minPosition.X * 1000.0,
						temp.minPosition.Y * 1000.0), fileType);
		for(size_t i = 0; i < machine.tools.GetCount(); i++){
			f.AddLine(
					wxString::Format(_T("[tooldef t%u d%g z%g"),
							machine.tools[i].slotNr,
							machine.tools[i].GetMaxDiameter() * 1000.0,
							machine.tools[i].GetPositiveLength() * 1000.0),
					fileType);
		}
	}

	bool flag = temp.WriteToFile(f);
	f.Write();
	f.Close();
	setlocale(LC_ALL, "");

	return flag;
}

void Run::Paint(bool showAnimation) const
{
	const Project * pr = parent;
	if(pr == NULL) return;

	::glPushMatrix();

	if(refWorkpiece > -1){
		Vector3 center = pr->workpieces[refWorkpiece].GetCenter();
		::glTranslatef(-center.x, -center.y, -center.z);
	}

	machine.Paint();

	if(refWorkpiece > -1){
		::glPushMatrix();
		::glMultMatrixd(machine.workpiecePosition.a);
		::glMultMatrixd(workpiecePlacement.a);
		if(showAnimation){
			simulator.Paint();
		}else{
			pr->workpieces[refWorkpiece].Paint();
			bool anySelected = false;
			for(size_t n = 0; n < generators.GetCount(); n++){
				assert(generators[n] != NULL);
				if(generators[n]->selected) anySelected = true;
			}
			for(size_t n = 0; n < generators.GetCount(); n++){
				assert(generators[n] != NULL);
				if(!anySelected || generators[n]->selected){
					generators[n]->Paint();
				}
			}
		}

		// Draw the "Touchpoint" symbol
		const float s = 0.02;
		glTranslatef(0, 0, touchoffHeight);

		glScalef(s, s, s);
		glRotatef(90, 1, 0, 0);
		touchpoint.Paint();
		glRotatef(90, 0, 1, 0);
		touchpoint.Paint();
		glRotatef(90, 0, 1, 0);
		touchpoint.Paint();
		glRotatef(90, 0, 1, 0);
		touchpoint.Paint();
		::glPopMatrix();
	}

	::glPopMatrix();
}

void Run::ToolpathToStream(wxTextOutputStream & stream)
{
//	toolPath.ToolpathToStream(f);
	throw(__FILE__ "Not yet implemented.");
}

void Run::ToStream(wxTextOutputStream& stream)
{
	stream << _T("Name:") << endl;
	stream << name << endl;
	stream << wxString::Format(_T("WorkpieceRef: %u"), refWorkpiece) << endl;
	stream << wxString::Format(_T("Tools: %u"), machine.tools.GetCount())
			<< endl;
	for(size_t n = 0; n < machine.tools.GetCount(); n++){
		stream << wxString::Format(_T("Tool: %u"), n) << endl;
		machine.tools[n].ToStream(stream);
	}
	stream << _T("Machine:") << endl;
	stream << machine.fileName.GetFullPath() << endl;
	GeneratorCollection gc;
	stream << wxString::Format(_T("Generators: %u"), generators.GetCount())
			<< endl;
	for(size_t n = 0; n < generators.GetCount(); n++){
		stream << wxString::Format(_T("Generator: %u"), n) << endl;
		size_t g;
		if(!gc.FindGenerator(generators[n], &g)) throw(__FILE__ "Cannot find generator.");
		stream << gc.GetName(g) << endl;
		generators[n]->ToStream(stream);
	}
}

bool Run::FromStream(wxTextInputStream& stream, int runNr, Project * project)
{
	wxString temp;
	temp = stream.ReadLine();
	if(temp.Cmp(_T("Name:")) != 0) return false;
	name = stream.ReadLine();
	temp = stream.ReadWord();
	if(temp.Cmp(_T("WorkpieceRef:")) != 0) return false;
	refWorkpiece = stream.Read32S();
	temp = stream.ReadWord();
	if(temp.Cmp(_T("Tools:")) != 0) return false;
	size_t NTools = stream.Read32S();
	machine.tools.Clear();
	for(size_t n = 0; n < NTools; n++){
		temp = stream.ReadWord();
		if(temp.Cmp(_T("Tool:")) != 0) return false;
		size_t index = stream.Read32S();
		if(index != n) return false;
		Tool temp;
		temp.FromStream(stream);
		machine.tools.Add(temp);
	}
	temp = stream.ReadLine();
	if(temp.Cmp(_T("Machine:")) != 0) return false;
	wxFileName fileName(stream.ReadLine());
	machine.Load(fileName);
	temp = stream.ReadWord();
	if(temp.Cmp(_T("Generators:")) != 0) return false;
	size_t N = stream.Read32();

	for(size_t n = 0; n < generators.GetCount(); n++)
		delete generators[n];
	generators.Clear();
	GeneratorCollection gc;
	for(size_t n = 0; n < N; n++){
		temp = stream.ReadWord();
		if(temp.Cmp(_T("Generator:")) != 0) return false;
		size_t index = stream.Read32S();
		if(index != n) return false;
		temp = stream.ReadLine();
		size_t generatorNr;
		if(!gc.FindGenerator(temp, &generatorNr)) return false;
		Generator* tempGen = gc.NewGenerator(generatorNr);
		tempGen->FromStream(stream);
		generators.Add(tempGen);
	}
	return true;
}

Vector3 Run::GetCenter(void) const
{
	Vector3 temp;
	if(machine.IsInitialized()){
		temp = machine.GetCenter();
	}
	return temp;
}

Workpiece* Run::GetWorkpiece(void)
{
	if(parent == NULL) return NULL;
	if(refWorkpiece < 0) return NULL;
	if(refWorkpiece >= parent->workpieces.GetCount()) return NULL;
	return &(parent->workpieces[refWorkpiece]);
}

const Workpiece* Run::GetWorkpiece(void) const
{
	if(parent == NULL) return NULL;
	if(refWorkpiece < 0) return NULL;
	if(refWorkpiece >= parent->workpieces.GetCount()) return NULL;
	return &(parent->workpieces[refWorkpiece]);
}

ToolPath* Run::GetSelectedToolpath(void)
{
	for(size_t n = 0; n < generators.GetCount(); n++){
		if(((generators[n]))->selected) return &((generators[n])->toolpath);
	}
	return NULL;
}
