///////////////////////////////////////////////////////////////////////////////
// Name               : ProtoToolpath.h
// Purpose            :
// Thread Safe        : No
// Platform dependent : No
// Compiler Options   :
// Author             : tobiassch
// Created            : 03.01.2017
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
#include "ProtoToolpath.h"

ProtoToolpath::ProtoToolpath()
{
	level = -1;
	parent = -1;
	next = -1;
	child = -1;
}

ProtoToolpath::~ProtoToolpath()
{
}