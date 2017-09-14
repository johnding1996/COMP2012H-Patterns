//FindLine Class
//Including the point data, functions for readind, finding and element accessing
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "point.h"
#include "fast.h"
#include "brute.h"

#ifndef FINDLINE
#define FINDLINE

class FindLine {
public:
	//Default constructor
	//Setting the height and width for rescaling
	FindLine():width(300), height(300) {};
	//Destructor
	~FindLine() {delete[] pts;}
	//Reading from input stream
	void read(std::istream&);
	//Reading from file
	void readFromFile(std::string filename = "inpupt.txt");
	//Running the fast method
	double fastFind();
	//Running the brute method
	double bruteFind();
	//Setting the scale
	void setScale(int, int);
	//The following member accessing functions are for drawing
	//Getting the number of points
	int getPointSize();
	//Accessing the rescaled x coordinate of a single point
	int pointX(int);
	//Accessing the rescaled x coordinate of a single point
	int pointY(int);
	//Getting the number of lines
	int getLineSize();
	//Accessing the number of points in a single line
	int lineLength(int);
	//Accessing the rescaled x coordinate of a single point in a specific line
	int linePointX(int, int);
	//Accessing the rescaled y coordinate of a single point in a specific line
	int linePointY(int, int);

private:
	//The point array
	Point* pts;
	//Size of the point array
	int size;
	//Clock for timing
	clock_t clk;
	//Find results
	//Copied from the Fast or Brute class
	std::vector<int> linesize;
	std::vector<Point> linepoint;
	//File input stream for file input
	std::ifstream inputfile;
	//The minimum and maximum coordinates for points for rescaling
	int minX, minY, maxX, maxY;
	//The size of frame for rescaling
	int width, height;
	//Helper functions for calculating the rescaled coordinates
	int rescaleX (const Point&);
	int rescaleY (const Point&);
	//Helper function for locating a single point in the linepoint vector
	void cumLength ();
};

#endif