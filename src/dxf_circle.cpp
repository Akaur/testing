# include "../include/dxf_2D.h"

circle :: circle ()
{
}

circle :: circle(point& pt1, point& pt2,int dlayer, string filename)
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

circle :: circle (point& pt1, point& pt2,int dlayer, string filename, int hflag, int hcolor)
{
	xStart = pt1.xCo;
	yStart = pt1.yCo;
	zStart = pt1.zCo;
	xEnd = pt2.xCo;
	yEnd = pt2.yCo;
	zEnd = pt2.zCo;
	layer = dlayer;
	dxfFileName = filename ;
	flag = hflag;
	pattern_name = "SOLID";
	color = hcolor;
	edges = 1;
	edge_type = 2;
	draw();
}


circle :: circle (point& pt1, point& pt2, int dlayer, string filename, int hflag, string p_name, int hcolor)
{
	xStart = pt1.xCo;
	yStart = pt1.yCo;
	zStart = pt1.zCo;
	xEnd = pt2.xCo;
	yEnd = pt2.yCo;
	zEnd = pt2.zCo;
	layer = dlayer;
	dxfFileName = filename ;
	flag = hflag;
	pattern_name = p_name;
	color = hcolor;
	edges = 1;
	edge_type = 2;
	draw();
}


void circle :: write_Entity()
{
	xMid = (xStart + xEnd) / 2;
	yMid = (yStart + yEnd) / 2;
	radius = sqrt((pow((xEnd - xMid),2)) + (pow((yEnd - yMid),2)));
	
	writeFile << " 0 \nCIRCLE \n 5 \n43"
		"\n 100 \nAcDbEntity"
		"\n 100 \nAcDbCircle"
		"\n 8 \n" <<layer<< "\n 62 \n256"
		"\n 370 \n-1 \n 6 \nByLayer "
		"\n 10 \n" << xMid << 
		"\n 20 \n" << yMid << 
		"\n 40 \n" << radius <<
		"\n";
}


void circle :: draw()
{
	writeFile.open(dxfFileName.c_str());
	read_Header();
	if ((flag == 0) || (flag == 1))
	{
		write_Hatch_Start();
		write_Hatch_Entity();
		write_Hatch_End();
	}
	write_Entity();
	read_Footer();
	writeFile.close ();
}
	


void circle :: write_Hatch_Entity()
{
	xMid = (xStart + xEnd) / 2;
	yMid = (yStart + yEnd) / 2;
	radius = sqrt((pow((xEnd - xMid),2)) + (pow((yEnd - yMid),2)));
	writeFile <<" 10 \n" <<xMid<<
		"\n 20 \n" <<yMid<<
		"\n 40 \n" <<radius<<
		"\n";
}




