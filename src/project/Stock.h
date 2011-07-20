///////////////////////////////////////////////////////////////////////////////
// Name               : Stock.h
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 03.07.2011
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
//$LastChangedDate: $
//$Revision: $
//$LastChangedBy: $
///////////////////////////////////////////////////////////////////////////////


#ifndef STOCK_H_
#define STOCK_H_

#include "StockMaterial.h"
#include "../3D/AffineTransformMatrix.h"
#include <wx/filename.h>

/*!\class Stock
 * \brief ...
 *
 * ...
 */

class Stock {
	// Constructor / Destructor
public:
	Stock();
	virtual ~Stock();
	// Member variables
public:

	wxFileName fileName;

	AffineTransformMatrix matrix;

	ArrayOfStockMaterial stockMaterials;

private:


	// Methods
public:

	void Paint(void);

};

#endif /* STOCK_H_ */