# include <cmath>
# include <cstring>
# include <fstream>
# include <iostream>

using namespace std;

class base 						 
{
	protected:

		double length, xStart, yStart, xEnd, yEnd, radius,
			xMid, yMid ; 
		ifstream readFile, ;
		ofstream writeFile ;
		string  dxfFileName, entityType, readwrite ;

	public :

		base () ;
		void set ( string, double, double, double, double ) ;
		void read_Header () ;
		void read_Footer () ;	

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
		void draw ( string ) ;

};    						


class circle : public base
{

	public :

		circle ( ) ;
		void intermediate();
		void set ( string, double, double, double, double y2 = 0 ) ;
		void write_Common_Part_Entity ();
		void write_Input_Part_Entity ();
		void draw ( string) ;


};


