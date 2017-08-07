///////////////////////////////////////////////////////////////////////////////
// Name               : Hull.h
// Purpose            :
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 29.06.2011
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

#ifndef HULL_H_
#define HULL_H_

#include "Vector3.h"
#include "Triangle.h"
#include "AffineTransformMatrix.h"
#include "Geometry.h"
#include <wx/string.h>
#include <wx/dynarray.h>

/*!\class HullEdge
 * \ingroup 3DObject
 * \brief Closed Hull
 *
 * Calculates a closed Hull from a TriangleSoup.
 */

class HullEdge {
	// Constructor/ Destructor
public:
	HullEdge();
	virtual ~HullEdge();

	// Member variables
public:
	size_t va, vb;
	size_t ta, tb;

	Vector3 n;

	// Methods
public:
};
WX_DECLARE_OBJARRAY(HullEdge, ArrayOfHullEdge);

/*!\class HullTriangle
 * \brief ...
 *
 * ...
 */

class HullTriangle {
	// Constructor/ Destructor
public:
	HullTriangle();
	virtual ~HullTriangle();

	// Member variables
public:
	size_t va, vb, vc;
	size_t ea, eb, ec;
	Vector3 n;

	// Methods
public:
};
WX_DECLARE_OBJARRAY(HullTriangle, ArrayOfHullTriangle);

/*!\class Hull
 * \brief ...
 *
 * ...
 */

class Hull {
	// Constructor/ Destructor
public:
	Hull();
	virtual ~Hull();

	// Member variables
public:
	wxString objectName;
	Vector3 color;
	bool visible;
	bool paintEdges;
	bool paintTriangles;
	bool paintVertices;

	AffineTransformMatrix matrix; //!< Transformation of the data.

private:
	ArrayOfVector3 v;
	ArrayOfHullEdge e;
	ArrayOfHullTriangle t;

	// Methods
public:
	void Paint(void) const;

	void Clear(void);
	void CopyFrom(const Geometry &geometry);
	void CopyTrianglesFrom(const Geometry &geometry);

	void ApplyTransformation(const AffineTransformMatrix &matrix);
	void ApplyTransformation(void);

	size_t AddTriangle(const Vector3 &a, const Vector3 &b, const Vector3 &c);
	size_t AddTriangleTransform(const Vector3 &a, const Vector3 &b,
			const Vector3 &c, const AffineTransformMatrix &transformMatrix);
	size_t AddTriangleWithNormals(const Vector3 &a, const Vector3 &b,
			const Vector3 &c, const Vector3 &na, const Vector3 &nb,
			const Vector3 &nc);
	size_t AddTriangleWithNormal(const Vector3 &a, const Vector3 &b,
			const Vector3 &c, const Vector3 &n);

	void AddQuad(const Vector3 &a, const Vector3 &b, const Vector3 &c,
			const Vector3 &d);
	void AddQuadTransform(const Vector3 &a, const Vector3 &b, const Vector3 &c,
			const Vector3 &d, const AffineTransformMatrix &transformMatrix);

	void CalcNormals(void);

	size_t GetVertexCount(void) const
	{
		return v.GetCount();
	}

	Vector3 GetVertex(const size_t i) const
	{
		return v[i];
	}

private:
	double DiffSquareAndAdd(const Vector3 &a, const Vector3 &b);

};
WX_DECLARE_OBJARRAY(Hull, ArrayOfHull);

#endif /* HULL_H_ */