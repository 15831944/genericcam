///////////////////////////////////////////////////////////////////////////////
// Name               : Run.h
// Purpose            : Defines a machine run.
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

#ifndef RUN_H_
#define RUN_H_

#include "../3D/Geometry.h"
#include "Toolbox.h"
#include "../machine/Machine.h"
#include "StockMaterial.h"
#include "Workpiece.h"
#include "ToolPath.h"
#include "../generator/TPGeneratorFast.h"
#include "../generator/TPGeneratorTest.h"

#include <wx/string.h>
#include <wx/textfile.h>
#include <wx/xml/xml.h>
#include <wx/dynarray.h>

/*!\class Run
 * \brief ...
 *
 * ...
 */

class Run {
	// Constructor / Destructor
public:
	Run();
	virtual ~Run();
	// Member variables
public:
	wxString name;
	bool selected;

	int workpieceNr;
//	ArrayOfObjectPlacement workpiecePlacements;
	AffineTransformMatrix workpiecePlacement;
	Machine machine;
	Toolbox toolbox;

	ToolPath toolPath;

	TPGeneratorFast ToolPathGenerator; // TODO: A generator? Here?

	// Methods
public:

	bool LoadGCode(wxFileName fileName);

	void Paint(void);
	void ToXml(wxXmlNode* parentNode);
	bool FromXml(wxXmlNode* node);

	void WriteToFile(wxTextFile &f); //TODO: Here?

	void SortTargets(void); // TODO: Autoplacing belongs to the Workpiece class!?

};
WX_DECLARE_OBJARRAY(Run, ArrayOfRun);

#endif /* RUN_H_ */
