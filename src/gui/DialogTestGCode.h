///////////////////////////////////////////////////////////////////////////////
// Name               : DialogTestGCode.h
// Purpose            : 
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 12.07.2017
// Copyright          : (C) 2017 Tobias Schaefer <tobiassch@users.sourceforge.net>
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

#ifndef DIALOGTESTGCODE_H_
#define DIALOGTESTGCODE_H_

#include "../StdInclude.h"
#include "../project/machine/GCodeBlock.h"
#include "gui.h"

class DialogTestGCode:public GUITestGCode {
public:
	DialogTestGCode(wxWindow* parent, DisplaySettings* settings);
	virtual ~DialogTestGCode();

	bool TransferDataToWindow(void);

	void OnText(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);

	DisplaySettings* settings;
};

#endif /* DIALOGTESTGCODE_H_ */
