# include "../include/dxf_2D.h"

circle :: circle () : base ()
{
}

void circle :: set ( string entitySubType, double x1, double y1, double x2, double y2 )
{
	base :: set ( entitySubType, x1, y1, x2, y2 ) ;
}

void circle :: intermediate()
{
	write_Common_Part_Entity ();
}


void circle :: write_Common_Part_Entity ()
{
	writeFile << " CIRCLE \n 5 \n 43 \n 100 \n AcDbEntity \n 100 \n"
				" AcDbCircle \n 8 \n 0 \n 62 \n 256 \n 370 \n -1 "
				"\n 6 \n ByLayer ";
	write_Input_Part_Entity();
}

void circle :: write_Input_Part_Entity()
{
	if ( entityType == " ")
	{ 
		radius = xEnd ;
		writeFile << "\n 10 \n "<< xStart <<
			" \n 20 \n" << yStart << 
			" \n 40 \n " << radius <<
			" \n  0 " ;
	}	
	else
	{
		xMid = ( xStart + xEnd ) / 2;
		yMid = ( yStart + yEnd ) / 2;
		radius = sqrt ( pow((xEnd - xMid),2) + pow(( yEnd - yMid ),2)),
		writeFile << " \n  10 \n "<< xMid << 
			" \n 20 \n " << yMid << 
			" \n  40 \n " << radius <<
			"\n  0 " ;
	}
}
	

void circle :: draw ( string fileName)
{
	dxfFileName = fileName ;
	writeFile.open(dxfFileName.c_str());
	read_Header();
	intermediate();
	read_Footer ();
	writeFile.close () ;
}


