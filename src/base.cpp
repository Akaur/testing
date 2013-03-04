# include "dxf_2D.h"

using namespace std ;

base :: base ()
{	
	entityType = "" ;
	xStart = yStart = xEnd = yEnd = radius = 0 ;
}


void base :: set ( string entitySubType, double x1, double y1, double x2, double y2 )
{ 
	entityType = entitySubType ;
	xStart = x1 ;
	yStart = y1;
	xEnd   = x2 ;
	yEnd   = y2 ;
}

void base :: read_Header ()
{
	readFile.open( "header.txt" ) ;
	while ( getline ( readFile, readwrite, '\n' ) )
	{
		writeFile << readwrite << endl ;
	}
	readFile.close () ;  
}

void base :: read_Footer ()
{
	readFile.open( "footer.txt" ) ;
	while ( getline ( readFile, readwrite, '\n' ) )
	{  
		writeFile << readwrite << endl ;
	} 
	readFile.close () ;
}


