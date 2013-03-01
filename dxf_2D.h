# include <cmath>
# include <cstring>
# include <fstream>
# include <iostream>

using namespace std ;

class base 						 
{
	protected :

		double length, xStart, yStart, xEnd, yEnd, radius,
			xMid, yMid ; 
		string  dxfFileName, entityType, writeHeaderFile, 
			writeEntityFile, writeFooterFile;

	public :

		base ( ) ;
		void set (double, double, double, double, string ) ;		

};


class line : public base
{

	public :

		line ( ) ;
		void set ( double, double, double, double, string ) ;
		void writeEntity ();
		void draw ( string ) ;

};    						


class circle : public base
{

	public :

		circle ( ) ;
		void set ( double, double, double, double, string ) ;
		void writeEntity ();
		void draw ( string) ;


};


