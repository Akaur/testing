# include <iostream>
# include <stdlib.h>
# include "src/dxf_2D.h" 

using namespace std;

	int main()
	{
		line l;
		l.set("horizontal", 45, 23, 30) ;
		l.draw("horizontal.dxf");
		
		/*line l;
		l.set("vertical",55,56,30);
		l.draw("vertcal.dxf");
		
		line l ;
		int x = 45, y = 23, z = 13, a = 46 ;
		l.set ( "rectangle", x, y, z, a ) ;
		l.draw ( "rectangle.dxf" ) ;*/

		circle c ;
		c.set (" ", 4, 50, 5 ) ;
		c.draw ( "circle.dxf" ) ;
		
		return 0 ;
	
	}
