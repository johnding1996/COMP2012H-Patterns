//Point Class
#include "point.h"

//Tolerance constant
const double Point::tol = 0.0000001;

//Copy constructor
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	ag = p.ag;
}

//Checking weather four points are coline
//For brute method
bool Point::coline (Point& p1, Point& p2, Point& p3) {
	//Calculate and set the angles
	angle(p1);
	angle(p2);
	angle(p3);
	//Compare the angles
	return (p1==p2)&&(p1==p3);
}

//Assign the relative angle
//For both methods
double Point::angle (Point& p) {
	double dx = p.x - x;
	double dy = p.y - y;
	double agp;
	//If dx = 0
	if (std::abs(dx)<tol) {
		//Set the angle (slope) to inf
		agp = std::numeric_limits<double>::infinity();
		//Otherwise direct division
	} else agp = dy / dx;
	//Set the angle to that point
	p.setAngle(agp);
	return agp;
}

//Overloading operators for comparing the relative angle
bool Point::operator< (const Point& p) const{
	return ((p.ag - ag)>tol);
}

//Overloading operators for comparing the relative angle
bool Point::operator== (const Point& p) const{
	//std::abs is overloaded for all numerical types
	return (std::abs(p.ag - ag)<tol);
}

//Overloading the output stream operator for output
std::ostream& operator<< (std::ostream& os, const Point& p) {
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}