# include <iostream>
# include <stdlib.h>
# include "dxf_2D.h" 

using namespace std;

	int main()
	{
		line l;
		l.set(55,56,30,0,"horizontal");
		l.draw("horizontal.dxf");
		
		/*line l;
		l.set(55,56,30,0,"vertical");
		l.draw("vertcal.dxf");
		
		line l ;
		int x = 45, y = 23, z = 13, a = 46 ;
		l.set ( x, y, z, a, "rectangle" ) ;
		l.draw ( "rectangle.dxf" ) ;*/

		circle c ;
		c.set ( 34, 35, 54, 55, "Circle from 2 points" ) ;
		c.draw ( "circle.dxf" ) ;
		
		return 0 ;
	
	}
