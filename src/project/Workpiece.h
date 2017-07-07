///////////////////////////////////////////////////////////////////////////////
// Name               : Workpiece.h
// Purpose            : The workpiece
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 29.03.2010
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

#ifndef WORKPIECE_H_
#define WORKPIECE_H_

/*!\class Workpiece
 * \ingroup document
 * \brief Workpiece for a Run
 *
 */

#include "StockMaterial.h"
#include "ObjectPlacement.h"
#include "Support.h"
#include "../3D/BooleanBox.h"
#include "../3D/BoundingBox.h"
#include "generator/DexelTarget.h"

#include <wx/txtstrm.h>
#include <wx/dynarray.h>

class Project;

class Workpiece:public BoundingBox {
	// Constructor / Destructor
public:
	Workpiece();
	Workpiece(const StockMaterial &material);
	virtual ~Workpiece();

	// Member variables
public:
	Project * parent; //!< Pointer back to the Project this Workpiece belongs to.
	wxString name;
	AffineTransformMatrix matrix;
	ArrayOfObjectPlacement placements;
	ArrayOfSupport supports;

	Geometry geometry;
	DexelTarget simulation;

	bool selected;

//	volatile bool hasRunningGenerator;

private:

	//TODO: Replace the BooleanBox with the simulation or geometry.
	BooleanBox bbox; ///< Redundant?

	// Methods
public:
	void ToStream(wxTextOutputStream & stream);
	bool FromStream(wxTextInputStream & stream);

	void InitSimulation(size_t maxCells);

	void Paint(void) const;
	void PaintSimulation(void) const;
	void Update(void);
//	void SortTargets(void);
};
WX_DECLARE_OBJARRAY(Workpiece, ArrayOfWorkpiece);

#endif /* WORKPIECE_H_ */
