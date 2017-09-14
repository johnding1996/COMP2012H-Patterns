//FindLine Class
#include "findline.h"

//Reading form the input stream
void FindLine::read(std::istream& input) {
	//Check the istream is at good state
	if (!input.good()) {
		std::cerr << "Fail to read input stream.";
		exit(0);
	}

	//Input size of the point array
	input >> size;
	//Check it is valid
	if (size<=0) {
		std::cerr << "Invalid input size.";
		exit(0);
	}

	//Define the point array by dynamic allocation
	pts = new Point[size];

	//Buffer for the coordinates
	int xdata, ydata;

	//Check if reached the end
	if (input.eof()) {
		std::cerr << "Unexpected end of file.";
		size = 0;
		exit(0);
	}
	//Input the x coordinate for the first point
	input >> xdata;
	//Check if reached the end
	if (input.eof()) {
		std::cerr << "Unexpected end of file.";
		size = 0;
		exit(0);
	}
	//Input the y coordinate for the first point
	input >> ydata;
	//Assign the first point
	pts[0].setCoor(xdata,ydata);
	//Set the minimum maximum coordinates by the coordinates of the first point
	minX = xdata;
	maxX = xdata;
	minY = ydata;
	maxY = ydata;

	//Input the rest coordinates
	for (int i=1; i<size; ++i) {
		//Check if reached the end
		if (input.eof()) {
			std::cerr << "Unexpected end of file.";
			size = i;
			exit(0);
		}
		//Input the x coordinate
		input >> xdata;
		//Check if reached the end
		if (input.eof()) {
			std::cerr << "Unexpected end of file.";
			size = i;
			exit(0);
		}
		//Input the y coordinate
		input >> ydata;
		//Assign the point
		pts[i].setCoor(xdata,ydata);
		//Change the minimum maximum coordinates accordingly
		if (xdata<minX) minX = xdata;
		if (xdata>maxX) maxX = xdata;
		if (ydata<minY) minY = ydata;
		if (ydata>maxY) maxY = ydata;
	}
	//Change a little to avoid the maximum and minimum coincide
	int Dx = maxX - minX;
	int Dy = maxY - minY;
	minX = minX - 1 - Dx/20;
	maxX = maxX + 1 + Dx/20;
	minY = minY - 1 - Dy/20;
	maxY = maxY + 1 + Dy/20;
}

//Reading from file
void FindLine::readFromFile(std::string filename) {
	//Set the ifstream by filename string
	inputfile.open(filename.c_str());
	//Check whether it is at good state
	if (!inputfile.good()) {
		//Report cannot open the file
		std::cerr << "Fail to read " << filename << ".";
		exit(0);

	}
	//Call to read from ifstream
	read(inputfile);

	//Close the ifstream
	inputfile.close();
}

//Run fast method
double FindLine::fastFind() {
	//Instance of the Fast class
	Fast f(size,pts);
	//Timing
	clk = clock();
	//Run fast find
	f.find();
	clk = clock() - clk;
	//Collect the result
	linesize = f.getLineSize();
	linepoint = f.getLinePoint();
	cumLength();
	//Return the CUP time
	return double(clk)/CLOCKS_PER_SEC*1000;
}

//Run brute method
double FindLine::bruteFind() {
	//Instance of the Brute class
	Brute b(size,pts);
	//Timing
	clk = clock();
	//Run brute find
	b.find();
	clk = clock() - clk;
	//Collect the result
	linesize = b.getLineSize();
	linepoint = b.getLinePoint();
	cumLength();
	//Return the CUP time
	return double(clk)/CLOCKS_PER_SEC*1000;
}

//Set the scale
void FindLine::setScale(int w, int h) {
	width = w;
	height = h;
}

//Get the number of points
int FindLine::getPointSize() {
	return size;
}

//Accessing the rescaled x coordinate of a single point
int FindLine::pointX(int id) {
	//Check whether the index is valid
	if(id<0||id>=size) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	return rescaleX(pts[id]);

}

//Accessing the rescaled x coordinate of a single point
int FindLine::pointY(int id) {
	//Check whether the index is valid
	if(id<0||id>=size) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	return rescaleY(pts[id]);

}

//Getting the number of lines
int FindLine::getLineSize() {
	return linesize.size();
}

//Accessing the number of points in a single line
int FindLine::lineLength(int id) {
	//Check whether the index is valid
	if(id<0||id>=(int)linesize.size()) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	//Substract the previous element
	//Since the size is after cummulated
	int prevlength;
	if (id == 0) prevlength = 0;
	else prevlength = linesize[id-1];
	return (linesize[id]-prevlength);
}

//Accessing the rescaled x coordinate of a single point in a specific line
int FindLine::linePointX(int idline, int idpoint) {
	//Check whether the index is valid
	if(idline<0||idline>=(int)linesize.size()) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	//Calculate the absolute index in the linepoint vector
	int id;
	if (idline==0) id = idpoint;
	else id = linesize[idline-1]+idpoint;
	//Check whether the index is valid
	if(id<0||id>=(int)linepoint.size()) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	return rescaleX(linepoint[id]);
}

//Accessing the rescaled y coordinate of a single point in a specific line
int FindLine::linePointY(int idline, int idpoint) {
	if(idline<0||idline>=(int)linesize.size()) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	//Calculate the absolute index in the linepoint vector
	int id;
	if (idline==0) id = idpoint;
	else id = linesize[idline-1]+idpoint;
	//Check whether the index is valid
	if(id<0||id>=(int)linepoint.size()) {
		std::cerr << "Accessing invalid index.";
		exit(0);
	}
	return rescaleY(linepoint[id]);
}

//Helper functions for calculating the rescaled x coordinate
int FindLine::rescaleX (const Point& p) {
	double x = (p.X()-minX)/(1.0*(maxX-minX));
	return (int)(x*width);
}

//Helper functions for calculating the rescaled x coordinate
int FindLine::rescaleY (const Point& p) {
	double y = (p.Y()-minY)/(1.0*(maxY-minY));
	return (int)(y*height);
}

//Helper function for locating a single point in the linepoint vector
void FindLine::cumLength () {
	for (int i=1; i<(int)linesize.size(); ++i) {
		linesize[i] = linesize[i] + linesize[i-1];
	}
}