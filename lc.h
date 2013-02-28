# include <iostream>
# include <cstring>

using namespace std ;

class library 						 
{

	protected :

		double length, xStart, yStart, xEnd, yEnd, radius ; 	
		string  dxfFileName, lineType, writeHeaderFile, writeEntityFile, writeFooterFile;

	public :

		library ( ) ;
		void set (double, double, double, double, string ) ;
		void set ( double, double, double ) ;		

};


class line : public library
{

	public :

		line ( ) ;
		void set ( double, double, double, double, string ) ;
		void draw ( string ) ;

};    						


class circle : public library
{

	public :

		circle ( ) ;
		void set ( double, double, double ) ;
		void draw ( ) ;


};


