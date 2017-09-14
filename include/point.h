//Point Class
#include <cmath>
#include <limits>
#include <iostream>

#ifndef POINT
#define POINT

class Point {
public:
	//Constructor
	Point():x(0),y(0),ag(0.0) {}
	Point(int xc, int yc):x(xc),y(yc),ag(0.0) {}
	Point(const Point& p);
	//Destructor
	~Point() {}

	//Setting functions
	void setCoor (int xc, int yc) {x = xc; y = yc;}
	void setAngle (double agc) {ag = agc;}

	//The coordinates accessing function
	int X() const {return x;}
	int Y() const {return y;}

	//Checking weather four points are coline
	//For brute method
	bool coline(Point& p1, Point& p2, Point& p3);

	//Assign the relative angle
	//For both methods
	double angle(Point& p);

	//Overloading operators for comparing the relative angle
	bool operator< (const Point&) const;
	bool operator== (const Point&) const;

	//Overloading the output stream operator for output
	friend std::ostream& operator<< (std::ostream& os, const Point& p);

private:
	//Coordinates
	int x, y;
	//Angle for sorting
	double ag;
	//Tolerance constant
	static const double tol;

};

#endif