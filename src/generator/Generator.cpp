///////////////////////////////////////////////////////////////////////////////
// Name               : Generator.cpp
// Purpose            : Abstract class for toolpath generators
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 22.08.2011
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

#include "Generator.h"

Generator::Generator()
{
	marginBelow = 0.0;
	marginSide = 0.0;

	settings = NULL;

	toolpath = NULL;
	toolpathGenerated = false;
	errorOccured = false;
}

void Generator::CopyFrom(const Generator * other)
{
	this->box = other->box;
	this->marginBelow = other->marginBelow;
	this->marginSide = other->marginSide;
}

Generator::~Generator()
{
	if(toolpath != NULL) delete toolpath;
}

void Generator::AddToPanel(wxPanel* panel, DisplaySettings* settings)
{
	this->settings = settings;
}

//void Project::GenerateToolPath(void)
//{
//	size_t i, j;
//	bool isUsed;
//	for(i = 0; i < targets.GetCount(); i++){
//		if(targets[i].toolpath.IsEmpty()){
//
//			isUsed = false;
//			for(j = 0; j < run[activeRun].placements.GetCount(); j++){
//				if(!run[activeRun].placements[j].isKeepout
//						&& run[activeRun].placements[j].targetNumber == i) isUsed =
//						true;
//			}
//
//			if(isUsed){
//
//				wxLogMessage(
//						wxString::Format(
//								_T("Generating toolpath for target %u:"), i));
//
//				run[activeRun].ToolPathGenerator.GenerateToolpath(targets[i],
//						toolbox.tools[0]);
//			}
//		}
//	}
//	CollectToolPath();
//}

//void Project::CollectToolPath(void)
//{
//	size_t i, n;
//	ToolPath temp;
//	run[activeRun].toolPath.Clear();
//	MachinePosition mp;
//	if(true){ // Startup move, to prevent WinPC-NC from messing up the toolpath.
//		mp.axisX = 0.0;
//		mp.axisY = 0.0;
//		mp.axisZ = this->stock.stockMaterials[activeStock].sz + 0.010;
//		mp.isCutting = false;
//		run[activeRun].toolPath.positions.Add(mp);
//		mp.axisZ = this->stock.stockMaterials[activeStock].sz + 0.011;
//		mp.isCutting = true;
//		run[activeRun].toolPath.positions.Add(mp);
//	}
//
//	for(i = 0; i < run[activeRun].placements.GetCount(); i++){
//		if(!run[activeRun].placements[i].isKeepout){
//			n = run[activeRun].placements[i].targetNumber;
//			if(!targets[n].toolpath.IsEmpty()){
//				temp = targets[n].toolpath;
//				temp.ApplyTransformation();
//				temp.ApplyTransformation(run[activeRun].placements[i].matrix);
//				run[activeRun].toolPath += temp;
//			}
//		}
//	}
//}

