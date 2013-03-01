# include "dxf_2D.h"

using namespace std ;

base :: base ()
{	
	xStart = yStart = xEnd = yEnd = radius = 0 ;
	entityType = "" ;
}


void base :: set ( double x1, double y1, double x2, double y2, string entitySubType )
{ 
	xStart = x1 ;
	yStart = y1;
	xEnd   = x2 ;
	yEnd   = y2 ;
	entityType = entitySubType ;
}

