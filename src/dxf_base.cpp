# include "../include/dxf_2D.h"

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

void base :: read_Header()
{	
	name = "./src/dxf_header.txt";
	readFile.open( name.c_str());
	
	if ((writeFile.is_open()) && (readFile.is_open()))
	{	
		while ( getline ( readFile, readwrite, '\n' ) )
		{
			writeFile << readwrite << endl ;
		}
	readFile.close () ;  
	}
	else
		cout <<"\n not opening file \n";
}


void base :: read_Footer()
{	
	name = "./src/dxf_footer.txt";
	readFile.open( name.c_str() ) ;

	if ((writeFile.is_open()) && (readFile.is_open()))
	{	
		while ( getline ( readFile, readwrite, '\n' ) )
		{  
			writeFile << readwrite << endl ;
		} 
	readFile.close ();
	}
	else 
		cout<<"\n not open footer\n";
}

