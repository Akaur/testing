# include "../include/dxf_2D.h"

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



void base :: solid_Hatch_Start_Part()
{
	writeFile << "HATCH \n 8 \n 0"
		"\n 62 \n " << color <<
		" \n 370 \n -1 \n 6 \n ByLayer"
		" \n 100 \n  AcDbEntity" 
		" \n 100 \n AcDbHatch \n ";
	solid_Entity_Type();
}

void base :: solid_Entity_Type()
{
	if (entityType == "rectangle")
	{
		edges = 4;
		edge_type = 1;
		
	}
	else
	{
		edges = 1;
		edge_type = 2;
	}
	
	writeFile << "2 \n" << pattern_Name << "\n 70 \n" << fill <<
		" \n 91 \n 1 \n 92 \n 1"
		" \n 93 \n" << edges << 
		" \n 72 \n " << edge_type <<"";
}

void base :: solid_Hatch_End_Part()
{
	writeFile << "50 \n 0.0 \n 51 \n 360.0 \n "
		" 97 \n 0 \n 52 \n"<< pattern_Angle <<" \n 41 \n" << pattern_Scale << "\n 0\n";
}


