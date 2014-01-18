///////////////////////////////////////////////////////////////////////////////
// Name               : ToolPath.h
// Purpose            : Describing the boundary of the volume to be cut away.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 30.03.2010
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
//$LastChangedDate: 2011-08-22 22:20:17 +0200 (Mo, 22 Aug 2011) $
//$Revision: 83 $
//$LastChangedBy: tobiassch $
///////////////////////////////////////////////////////////////////////////////

/*!\class ToolPath
 * \code #include "ToolPath.h"\endcode
 * \brief Describes the boundary of the volume to be cut away.
 *
 */

#ifndef TOOLPATH_H_
#define TOOLPATH_H_

#include "../3D/AffineTransformMatrix.h"
#include "../machine/MachinePosition.h"
#include "../3D/AffineTransformMatrix.h"
#include "../3D/Vector3.h"
#include <wx/dynarray.h>
#include <wx/textfile.h>

class ToolPath {
	// Constructor / Destructor

public:
	ToolPath();
	virtual ~ToolPath();

	// Member variables
public:
	AffineTransformMatrix matrix;

	ArrayOfMachinePosition positions;

	Vector3 colorMoving;
	Vector3 colorCutting;

MachinePosition minPosition,maxPosition;


	// Methods
public:

	ToolPath & operator+=(const ToolPath &a);
	const ToolPath operator+(const ToolPath &a) const;
	void Clear(void);
	bool IsEmpty(void) const;
	void ApplyTransformation(void);
	void ApplyTransformation(const AffineTransformMatrix &matrix);
	void Paint(void);
	void CleanPath(double tolerance = 0.0002);
	void WriteToFile(wxTextFile &f);
	void CalculateMinMaxValues(void);
};
WX_DECLARE_OBJARRAY(ToolPath, ArrayOfToolPath)
;

#endif /* TOOLPATH_H_ */