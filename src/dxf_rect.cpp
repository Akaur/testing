# include "../include/dxf_2D.h"


rectangle :: rectangle()
{
}


rectangle :: rectangle (point& pt1, point& pt2, int dlayer, string filename)
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


rectangle :: rectangle (point& pt1, point& pt2, int dlayer, string filename, int hflag, int hcolor)
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
	edges = 4;
	edge_type = 1;
	draw();
}

rectangle :: rectangle (point& pt1, point& pt2, int dlayer, string filename, int hflag, string p_name, int hcolor)
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
	edges = 4;
	edge_type = 1;
	draw();
}


void rectangle :: write_Entity ()
{
	writeFile << "0\nLWPOLYLINE"
		" \n 5 \n43"
		" \n 100 \nAcDbEntity"
		" \n 100 \nAcDbPolyLine"
		" \n 8 \n" <<layer<< "\n 62 \n256"
		" \n 90 \n4 \n 70 \n1 \n 43 \n0.0" 
		" \n 10 \n" << xStart << 
		" \n 20 \n" << yStart << 
		" \n 10 \n" << xStart <<
		" \n 20 \n" <<  yEnd << 
		" \n 10 \n" << xEnd <<
		" \n 20 \n" << yEnd << 
		" \n 10 \n"<< xEnd << 
		" \n 20 \n" <<yStart<< 
		" \n" ;
}


void rectangle :: draw()
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


void rectangle :: write_Hatch_Entity()
{
	writeFile <<"10 \n" << xStart <<
		"\n 20 \n" << yStart <<
		"\n 11 \n" << xStart <<
		"\n 21 \n" << yEnd <<
		"\n 72 \n1"
		"\n 10 \n" << xStart <<
		"\n 20 \n" << yEnd <<
		"\n 11 \n" << xEnd <<
		"\n 21 \n" << yEnd <<
		"\n 72 \n1"
		"\n 10 \n" << xEnd <<
		"\n 20 \n" << yEnd <<
		"\n 11 \n" << xEnd <<
		"\n 21 \n" << yStart <<
		"\n 72 \n1"
		"\n 10 \n" << xEnd <<
		"\n 20 \n" << yStart <<
		"\n 11 \n" << xStart <<
		"\n 21 \n" << yStart <<
		"\n";
}

