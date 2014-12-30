///////////////////////////////////////////////////////////////////////////////
// Name               : ToolPanel.cpp
// Purpose            : 2D view of a tool.
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 28.02.2010
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


#include "ToolPanel.h"
#include <wx/log.h>

ToolPanel::ToolPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos,
		const wxSize& size, long style) :
	wxPanel(parent, id, pos, size, style)
{

	this->SetBackgroundColour(wxColour(200, 200, 200));

	tool = NULL;


	// Connect Events
	this->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler( ToolPanel::OnLeftDown ));
	this->Connect(wxEVT_MOTION, wxMouseEventHandler( ToolPanel::OnMotion ));
	this->Connect(wxEVT_PAINT, wxPaintEventHandler( ToolPanel::OnPaint ));
	this->Connect(wxEVT_SIZE, wxSizeEventHandler( ToolPanel::OnSize ));
}

ToolPanel::~ToolPanel()
{
	// Disconnect Events
	this->Disconnect(wxEVT_LEFT_DOWN,
			wxMouseEventHandler( ToolPanel::OnLeftDown ));
	this->Disconnect(wxEVT_MOTION, wxMouseEventHandler( ToolPanel::OnMotion ));
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler( ToolPanel::OnPaint ));
	this->Disconnect(wxEVT_SIZE, wxSizeEventHandler( ToolPanel::OnSize ));
}

void ToolPanel::InsertTool(Tool& t)
{
	tool = &t;
	this->Refresh();
}

void ToolPanel::OnSize(wxSizeEvent& event)
{
	this->Refresh();
}

void ToolPanel::OnPaint(wxPaintEvent& event)
{

	if(tool == NULL) return;

	wxPoint temp;
	wxPaintDC dc(this);
	wxSize sz = GetClientSize();

	float scaleX = (float) sz.x / tool->GetMaxDiameter();
	float scaleY = (float) sz.y / (tool->GetPositiveLength()
			+ tool->GetNegativeLength());

	float scaleFactor = (scaleX < scaleY)? scaleX : scaleY;
	scaleFactor *= 0.9;

	int mx = sz.x / 2;
	int my = (int) (scaleY * tool->GetNegativeLength());

	dc.CrossHair(mx, my);


	unsigned int i;

	for(i = 0; i < tool->contour.Count(); i++){

		if(tool->contour[i].isCutting)
			dc.SetPen(*wxRED_PEN);
		else
			dc.SetPen(*wxBLACK_PEN);

		dc.DrawLine(mx + scaleFactor * tool->contour[i].p1.x, my + scaleFactor
				* tool->contour[i].p1.z, mx + scaleFactor
				* tool->contour[i].p2.x, my + scaleFactor
				* tool->contour[i].p2.z);
		dc.DrawLine(mx - scaleFactor * tool->contour[i].p1.x, my + scaleFactor
				* tool->contour[i].p1.z, mx - scaleFactor
				* tool->contour[i].p2.x, my + scaleFactor
				* tool->contour[i].p2.z);
	}


	//wxLogMessage((linkedField == NULL)? _T("NULL") : _T("not NULL"));


	//	text = wxString::Format(_T("%u elements in tool."), tool->elements.Count());
	//	dc.DrawText(text, 10, 10);
}

void ToolPanel::OnMotion(wxMouseEvent& event)
{
	if(tool == NULL) return;
}

void ToolPanel::OnLeftDown(wxMouseEvent& event)
{
	if(tool == NULL) return;

}
