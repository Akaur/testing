# include "../include/dxf_2D.h"


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

void base :: write_Hatch_Start()
{
	writeFile << "0 \nHATCH \n 8 \n0"
		"\n 62 \n" << color <<
		"\n 370 \n-1 \n 6 \nByLayer"
		"\n 100 \n AcDbEntity" 
		"\n 100 \nAcDbHatch"
		"\n 2 \n" << pattern_name <<
		"\n 70 \n" <<flag<< "\n 91 \n1"
	 	"\n 92 \n1"
		"\n 93 \n" << edges <<
		"\n 72 \n" << edge_type <<
		"\n";
}

	

void base :: write_Hatch_End()
{
	writeFile << "50 \n0.0 \n 51 \n360.0"
		"\n 97 \n0 \n 52 \n60"
		"\n 41 \n1.0 \n";
}

