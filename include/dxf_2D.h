# include <cmath>
# include <cstring>
# include <fstream>
# include <iostream>

using namespace std;

class base 						 
{
	public:

		double 	xCo, yCo, zCo, 
			xStart, yStart, zStart, 
			xEnd, yEnd, zEnd,
			xMid, yMid,radius; 
		ifstream readFile;
		int 	flag, edges, edge_type, color, layer;
		ofstream writeFile ;
		string  dxfFileName, readwrite, pattern_name, name;

	public :
		void read_Header();
		void read_Footer();
		void write_Hatch_Start();
		void write_Hatch_End();

};


class point : public base
{
	public:
		point();
		point(double, double y = 0, double z = 0);
};


class circle : public base
{
	public :
		circle();
		circle(point&, point&, int, string);
		circle(point&, point&, int, string, int hflag, int hcolor=256);
		circle(point&, point&, int, string, int hflag, string p_name = "asci31", int hcolor=256);		
		void write_Entity();
		void write_Hatch_Entity();
		void draw();
};



class line : public base
{
	public :
		line();
		line(point&, point&, int, string);
		void write_Entity();
		void draw();

};


class rectangle : public base
{
	public :
		rectangle();
		rectangle(point&, point&, int, string);
		rectangle(point&, point&, int, string, int hflag, int hcolor=256);
		rectangle(point&, point&, int, string, int hflag, string p_name, int hcolor=256);
		void write_Entity();
		void write_Hatch_Entity();
		void draw();

};


