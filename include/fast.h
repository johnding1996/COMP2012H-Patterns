//Fast Class
//Including the brute method and its results
#include <iostream>
#include <algorithm>
#include <vector>

#include "point.h"

#ifndef FAST
#define FAST

class Fast {
public:
	//Constructors
	Fast() {}
	Fast(int s, Point* p):size(s),pts(p) {}
	//Destructor
	~Fast() {}

	//Fast method
	void find();

	//Getting functions for retuning the results
	std::vector<int> getLineSize();
	std::vector<Point> getLinePoint();


private:
	//Size of the point array
	int size;
	//Pointer of the point array
	//The array is located in the dynamic array of FindLine class
	Point* pts;
	//Results
	//The vector of line sizes
	std::vector<int> linesize;
	//The vector of points on each lines
	std::vector<Point> linepoint;


};

#endif