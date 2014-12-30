///////////////////////////////////////////////////////////////////////////////
// Name               : DialogToolbox.h
// Purpose            : A window to edit tools in the toolbox.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 14.03.2010
// Copyright          : (C) 2010 Tobias Schaefer <tobiassch@users.sourceforge.net>
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


#ifndef TOOLBOXFRAME_H_
#define TOOLBOXFRAME_H_

#include "gui.h"
#include "../project/Project.h"

class DialogToolbox:public GUIToolbox {
	// Constructor/ Destructor

public:
	DialogToolbox(wxWindow* parent);
	virtual ~DialogToolbox();

	// Member Variables

	Project * linkedProject;

	unsigned int selectedTool;
	unsigned int selectedElement;

	// Methods
public:

	void InsertProject(Project *project);
	void SetController(Control3D& control);

	void OnClose(wxCommandEvent& event);
	void OnChangeStereo3D(wxCommandEvent& event);

	bool TransferDataToWindow(void);
	bool TransferDataFromWindow(void);


	void OnNewTool( wxCommandEvent& event ) ;
	void OnUpdateTool( wxCommandEvent& event ) ;
	void OnDeleteTool( wxCommandEvent& event ) ;
	void OnShapeNew( wxCommandEvent& event ) ;
	void OnShapeUpdate( wxCommandEvent& event ) ;
	void OnShapeDelete( wxCommandEvent& event ) ;
	void OnShapeSelect( wxListEvent& event ) ;



};

#endif /* TOOLBOXFRAME_H_ */