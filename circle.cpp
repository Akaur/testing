# include "dxf_2D.h"

using namespace std ;

circle :: circle () : base ()
{
}

void circle :: set ( double x1, double y1, double x2, double y2, string entitySubType )
{
	base :: set ( x1, y1, x2, y2, entitySubType ) ;
	writeEntity ();
}

void circle :: writeEntity ()
{
	ofstream writeCircle ( "circle.txt" ) ;
	if ( entityType == " ")
	{ 	
		radius = xEnd ;
		//if ( writeCircle.is_open () )
		//{
		writeCircle << " CIRCLE \n 5 \n 43 \n 100 \n AcDbEntity \n 100 \n"
				" AcDbCircle \n 8 \n 0 \n 62 \n 256 \n 370 \n -1 "
				"\n 6 \n ByLayer \n 10 \n "<< xStart << " \n 20 \n"
				<< yStart << " \n 30 \n 0.0 \n 40 \n "<< radius <<
				"\n  0 " ;
		writeCircle.close () ;
		//}
	}
	else
	{
		//if ( writeCircle.is_open () )
		//{
		xMid = ( xStart + xEnd ) / 2;
		yMid = ( yStart + yEnd ) / 2;
		radius = sqrt ( pow((xEnd - xMid),2) + pow(( yEnd - yMid ),2)),
		writeCircle << " CIRCLE \n 5 \n 43 \n 100 \n AcDbEntity \n 100 \n"
				" AcDbCircle \n 8 \n 0 \n 62 \n 256 \n 370 \n -1 "
				"\n 6 \n ByLayer \n 10 \n "<< xMid << " \n 20 \n " 
				<< yMid << " \n 30 \n 0.0 \n 40 \n " << radius <<
				"\n  0 " ;
		writeCircle.close () ;
		//}
	}
}
	

void circle :: draw ( string fileName)
{
	dxfFileName = fileName ;
	ifstream readHeader("header.txt");
	ifstream readFooter("footer.txt");
	ifstream readCircle("circle.txt");
	ofstream writeOutput(dxfFileName.c_str());
	
	while ( getline ( readHeader, writeHeaderFile, '\n' ) )
	{
		writeOutput << writeHeaderFile << endl ;
	}
	while ( getline ( readCircle, writeEntityFile, '\n' ) )
	{ 
		writeOutput << writeEntityFile << endl ;
	}
	while ( getline ( readFooter, writeFooterFile, '\n' ) )
	{  
		writeOutput << writeFooterFile << endl ;
	}  
		
	readHeader.close () ;        
	readCircle.close () ;
	readFooter.close () ;
	writeOutput.close () ;
}
