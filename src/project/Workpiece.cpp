///////////////////////////////////////////////////////////////////////////////
// Name               : Workpiece.cpp
// Purpose            : The workpiece.
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

#include "Workpiece.h"

#include <GL/gl.h>
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfWorkpiece)

Workpiece::Workpiece()
{
	selected = false;
}

Workpiece::Workpiece(const StockMaterial &material) :
		StockMaterial(material)
{
	selected = false;
	box.SetSize(material.sx, material.sy, material.sz);
	BooleanBox b(0.1, 0.1, 0.1);
	box -= b;
}

Workpiece::~Workpiece()
{
}

void Workpiece::Paint()
{
	if(glIsEnabled(GL_COLOR_MATERIAL)){
		glColor3f(color.x, color.y, color.z);
		box.Paint();
		StockMaterial::Paint(0.2, false);
	}else{
		box.Paint();
		StockMaterial::PaintWireBox();
	}
}

void Workpiece::Refresh()
{
	box.SetSize(sx, sy, sz);
}
