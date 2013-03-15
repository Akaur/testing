# include <iostream>
# include <stdlib.h>
# include "../include/dxf_2D.h" 

using namespace std;

	int main()
	{
		
		point p1(23,45), p2(34,67), p3(45.32,23.55);
		
		// you can choose layer between 1 -5 ,here chooses 1 layer
		line l(p1,p2,1,"line.dxf");  	// create line line.dxf by passing two points p1 and p2.

		/*   create rectangle with two points
		     2 layer
		     1 for solid fill flag
		     color code 23 (1-256)
		*/
		rectangle room(p1,p2,2,"rect.dxf",1, 8);

		/* 3 layer
		   0 for pattern fill
		   pattern_name = "paisley"
		   color = 15
		*/
		rectangle bedroom(p1,p3,3,"bedroom.dxf",0,"paisley",15);
		
		/* create circle
		   4 layer
		   1 for solid fill
		   color = 34
		*/
		circle c(p1,p2,4,"circle.dxf",1,34);
		
		/* 5 layer
		   0 for pattern fill
		   pattern_name
		   200 color code
		*/
		circle c1(p2,p3,5,"pattern.dxf",0,"paisley", 200);
		return 0 ;
	
	}
