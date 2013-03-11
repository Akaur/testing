# include <iostream>
# include <stdlib.h>
# include "../include/dxf_2D.h" 

using namespace std;

	int main()
	{
		/*line l;
		l.set("horizontal", 5, 23, 11) ;
		l.draw("horizontal.dxf", "1","231");
		
		/*line l1;
		l1.set("vertical",55,56,30);
		l1.draw("vertcal.dxf");*/
		
		// 0 for pattern fill
		// rectangle with pattern ansi31,p_angel=30.0 p_scale = 2.0 color =121
		line l ;
		double x1 = 45.344, y1 = 23.566, x2 = 13.134, y2 = 46.78 ;
		l.set ( "rectangle", x1, y1, x2, y2 ) ;
		l.draw ( "rectangle.dxf", 0, "ansi31", 30.0, 2.0, 121);
		

		// 1 for solid fill
		// color=12
		/*line l ;
		int x1 = 45, y1 = 23, x2 = 13, y2 = 46 ;
		l.set ( "rectangle", x1, y1, x2, y2 ) ;
		l.draw ( "rectangle.dxf", 1,12);
		

		// 1 for solid fill, color =123
		circle c ;
		c.set ("circle ", 4, 50, 50 ) ;
		c.draw ( "circle.dxf", 1,123);
		*/
		

		// 0 for pattern fill
		// p_name =honeycomb
		//can also specify p_scale and p_angle 
		double rad = 21.7;
		circle c1;
		c1.set("circle", x1, y1, rad);
		c1.draw("circle.dxf", 0, "honeycomb");
		return 0 ;
	
	}
