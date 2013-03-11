# include <cmath>
# include <cstring>
# include <fstream>
# include <iostream>

using namespace std;

class base 						 
{
	protected:

		double length, xStart, yStart, xEnd, yEnd, radius,
			xMid, yMid, pattern_Scale, pattern_Angle ; 
		ifstream readFile;
		int fill, edges, edge_type, color;
		ofstream writeFile ;
		string  dxfFileName, entityType, readwrite, 
			pattern_Name, name;

	public :

		base () ;
		void set( string, double, double, double, double ) ;
		void read_Header();
		void read_Footer();
		void solid_Hatch_Start_Part ();
		void solid_Hatch_End_Part ();
		void solid_Entity_Type();

};


class circle : public base
{

	public :

		circle ( ) ;
		void intermediate();
		void set ( string, double, double, double, double y2 = 0 ) ;
		void write_Common_Part_Entity();
		void write_Input_Part_Entity();
		void draw(string, int hfill = 1, int hcolor = 256);
		void write ();
		void draw(string, int hfill, string p_name, double p_angle = 0.0, double p_scale = 1.0, int hcolor = 256);


};



class line : public base
{

	public :

		line ( ) ;
		void set ( string, double, double, double, double y2 = 0) ;
		void intermediate();
		void write_Common_Part_Entity ();
		void write_Input_Part_Entity ();
		void write_Entity ();
		void write();
		void draw (string, int hfill =1, int hcolor = 256);	
		void solid_Entity_Write();
		void draw(string, int hfill, string p_name, double p_angle = 0.0, double p_scale = 1.0, int color = 256);


};    						


