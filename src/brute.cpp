//Brute Class
#include "brute.h"

//Brute method
void Brute::find() {
	//Finding the line with length >=4 by exhaustive search
	for (int a=0; a<(size-3); ++a) {
		for (int b=a+1; b<(size-2); ++b) {
			for (int c=b+1; c<(size-1); ++c) {
				for (int d=c+1; d<size; ++d) {
					//Checking if coline
					if (pts[a].coline(pts[b],pts[c],pts[d])) {
						//The line length is always 4
						//Inserting the line length to the linesize vector
						linesize.push_back(4);
						//Output to the command line
						std::cout << 4 << ':' << ' ';
						//Insersting the line points to the linepoint vector
						linepoint.push_back(pts[a]);
						linepoint.push_back(pts[b]);
						linepoint.push_back(pts[c]);
						linepoint.push_back(pts[d]);
						//Output to the command line
						//Using the overloaded output stream operator
						std::cout << pts[a];
						std::cout << " -> " << pts[b];
						std::cout << " -> " << pts[c];
						std::cout << " -> " << pts[d];
						std::cout << std::endl;
					}
				}
			}
		}
	}
}

//Getting the linesize vector
std::vector<int> Brute::getLineSize() {
	return linesize;
}

//Getting the linesize vector
std::vector<Point> Brute::getLinePoint() {
	return linepoint;
}