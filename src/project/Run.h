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

/*!\class Run
 * \ingroup document
 * \brief Single run of a machine
 *
 * The workpiecePlacement matrix herein is for rotating the workpiece.
 *
 * The machine itself contains another matrix used for placing the
 * workpiece in the machine.
 *
 * \todo: Implement copy and assignment constructors.
 */

#include "generator/Generator.h"
#include "FlipDrillPattern.h"
#include "Workpiece.h"
#include "machine/Machine.h"

#include "../3D/Geometry.h"
#include "../3D/OpenGLImage.h"
#include "../3D/AffineTransformMatrix.h"

#include <wx/filename.h>
#include <wx/txtstrm.h>
#include <wx/string.h>
#include <wx/dynarray.h>

class Project;
class Run {
	friend class Project;

	// Constructor / Destructor
public:
	Run();
	Run(const Run& other); //!< Copy constructor
	Run& operator=(const Run& other); ///< Assignment operator
	virtual ~Run();

	// Member variables
public:
	Project * parent; ///< Pointer back to the Project this Run belongs to.
	wxString name;

	int prevRun; ///< Link to the previous Run
	int refWorkpiece; ///< Workpiece reference

	Machine machine; ///< Machine used in this run
	ArrayOfTool tools; ///< Tool%s in the Machine
	ArrayOfGeneratorPointer generators; ///< List of Generator%s applied to the workpiece in this run

	AffineTransformMatrix workpiecePlacement; //!< For flipping the workpiece to machine the other sides.
	FlipDrillPattern pattern; //!< Experimental: FlipDrillPattern

	float touchoffHeight; ///< Flag to set the position of the touchoff. This can be below the workpiece or at the top of it. Not to be neglected or the machine-bed will get a scar.

	bool selected; ///< Flag if this run is selected.
private:
	int selectedTool;
	OpenGLImage touchpoint;

//	bool modified;
//	int workpieceNr;
//	ArrayOfToolPath toolpaths;

private:
	mutable GLuint textureID;
	mutable bool isOGLInit; ///< Controls the setup of OpenGL elements on the first evaluation of the Paint function.

	// Methods
public:
	void Update(void);

	void GenerateToolpaths(void);
	bool SaveToolpaths(wxFileName fileName);

	Vector3 GetCenter(void) const;
	void Paint(void) const;

	void ToStream(wxTextOutputStream & stream);
	bool FromStream(wxTextInputStream & stream, int runNr, Project * project);

	void ToolpathToStream(wxTextOutputStream & stream);

private:
	Workpiece* GetWorkpiece(void);
	const Workpiece* GetWorkpiece(void) const;

};
WX_DECLARE_OBJARRAY(Run, ArrayOfRun);

#endif /* RUN_H_ */
