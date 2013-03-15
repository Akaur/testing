# include "../include/dxf_2D.h"


line :: line()
{
}

line :: line (point& pt1, point& pt2, int dlayer,string filename)
{
	xStart = pt1.xCo;
	yStart = pt1.yCo;
	zStart = pt1.zCo;
	xEnd = pt2.xCo;
	yEnd = pt2.yCo;
	zEnd = pt2.zCo;
	layer = dlayer;
	dxfFileName = filename ;
	draw();
}


void line :: write_Entity()
{	
	writeFile << " 0 \nLINE"
		"\n 5 \n43"
		"\n 100 \nAcDbEntity"
		"\n 100 \nAcDbLine"
		"\n 8 \n" <<layer<<
		"\n 62 \n256"
		"\n 370 \n-1"
		"\n 6 \nByLayer"
		"\n 10 \n" << xStart <<
		"\n  20 \n" << yStart << 
		"\n 30 \n" << zStart <<
		"\n 11 \n" << xEnd << 
		"\n 21 \n" << yEnd <<
		"\n 31 \n" << zEnd <<
		"\n";
}


void line :: draw()
{
	writeFile.open(dxfFileName.c_str());
	read_Header();
	write_Entity();
	read_Footer();
	writeFile.close ();
}
			


