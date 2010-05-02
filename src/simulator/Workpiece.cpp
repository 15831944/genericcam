//============================================================================
// Name        : Workpiece.cpp
// Author      : Tobias Schaefer
// Version     : 0.1
// Created on  : 29.03.2010
// Copyright   : (c) 2010
// Description : CAM Software
//============================================================================


#include "Workpiece.h"
#include <GL/gl.h>
#include <wx/log.h>

Workpiece::Workpiece()
{

	s.AddBox(0.4, 0.3, 0.1);
	//s.SetSphere(0.2);
	//	if(gts_surface_is_closed(s.s)){
	//		wxLogMessage(_T("Surface is closed!"));
	//	}else{
	//		wxLogMessage(_T("Surface is open!"));
	//	}


	//s.SelfTest();

//	s.Statistics();

	CSGSurface b;
	//b.SetSphere(0.3);
	b.AddBox(0.4, 0.3, 0.1);
	b.Translate(-0.2, -0.15, 0.05);

//	b.Statistics();

	//b.SelfTest();
	s.BooleanRemove(&b);

//	s.Statistics();


//	s.SelfTest();
}

Workpiece::~Workpiece()
{

}

void Workpiece::Paint()
{
	s.Paint();
}