///////////////////////////////////////////////////////////////////////////////
// Name               : DialogToolpathGenerator.h
// Purpose            : Dialog to add, update and delete toolpath generators
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 09.02.2015
// Copyright          : (C) 2015 Tobias Schaefer <tobiassch@users.sourceforge.net>
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

#ifndef DIALOGTOOLPATHGENERATOR_H_
#define DIALOGTOOLPATHGENERATOR_H_

/*!\class DialogToolpathGenerator
 * \brief Dialog to add, update and delete toolpath generators.
 *
 * A lot of dynamic casting is done in this dialog class. The parameters hidden
 * in the derived classes, the parent class does not know about.
 */

#include "gui.h"
#include <wx/cmdproc.h>

#include "../project/Project.h"
#include "../generator/Generator.h"

#include "DisplaySettings.h"

class DialogToolpathGenerator:public GUIToolpathGenerator {
public:
	DialogToolpathGenerator(wxWindow* parent, Project * project,
			wxCommandProcessor * commandProcessor, DisplaySettings * settings);
	virtual ~DialogToolpathGenerator();

	Project* project;
	wxCommandProcessor * commandProcessor;
	DisplaySettings * settings;

	bool TransferDataToWindow(void);
	bool TransferDataFromWindow(void);

	void OnClose(wxCloseEvent& event);
	void OnSelectRun(wxCommandEvent& event);
	void OnSelectToolpath(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
	void OnChangeText(wxCommandEvent& event);
	void OnSelectArea(wxCommandEvent& event);
	void OnPageChanged(wxChoicebookEvent& event);
	void OnUpdate(wxCommandEvent& event);
	void OnResetChanges(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnClose(wxCommandEvent& event);

private:
	Generator ** generators;
	Generator * NewGenerator(int generatorNr);
	int GetSelectedToolpath(int runNr);
	int GetGeneratorNr(int runNr, int toolpathNr);

	BoundingBox box;
	float marginSides;
	float marginBelow;

};

#endif /* DIALOGTOOLPATHGENERATOR_H_ */