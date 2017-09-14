//Fast Class
#include "fast.h"

//Fast method
void Fast::find() {
	//For loop to traversing the point as the origin
	for (int i=0; i<(size-3); ++i) {
		//For loop to calculate the angle of the point after the origin
		for (int j=i+1; j<size; ++j) {
			(pts[i]).angle(pts[j]);

		}
		//Sorting by the angle
		//Using the overloaded less than operator of the Point class
		std::sort(pts+(i+1), pts+size);

		//Check the repetition of the angles
		Point curpt = pts[i+1];

		//Flag for whether a line is found
		bool isline = false;
		//Counting for the number of points in the current line
		int cnt = 2;

		//Traversing the sorted angle array
		for (int k=i+2; k<size; ++k) {
			//If the neighbor elements are the same
			if (curpt==pts[k]) {
				//Increment to the count
				++cnt;
				//If there are 4 points already
				//Admit it is a line
				if (cnt>=4) isline = true;
			}
			//If the neighbor elements are different
			//Or have reached the end of the array
			if (!(curpt==pts[k])||k==(size-1)) {
				//If the last element of the array is included
				//Modify the counter k to include it in that line
				if (k==(size-1)&&curpt==pts[k]) ++k;
				//If at this time we have recorded a line
				if (isline) {
					//Check whether it is a repeated line that have been outputted
					//Flag for repeated line
					bool isrepeatedline = false;
					//Traversal the origin points that have been used
					for (int m=0; m<i; ++m) {
						(pts[i]).angle(pts[m]);
						//If one of them is one this line
						if (curpt==pts[m]) {
							//Report finding repeated line
							isrepeatedline = true;
							break;
						}
					}
					//Only output the non-repeated lines
					if (!isrepeatedline) {
						//Inserting the line size
						linesize.push_back(cnt);
						//Output to the command line
						std::cout << cnt << ':' << ' ';
						//Inserting the origin to the line point vector
						//And output to the command line
						linepoint.push_back(pts[i]);
						std::cout << pts[i];
						//Inserting the rest line points
						//And output to the command line
						for (int l=k-cnt+1; l<k; ++l) {
							linepoint.push_back(pts[l]);
							std::cout << " -> " << pts[l];
						}
					std::cout << std::endl;
					}

				}
				//If have already reached end, break the loop
				if (k==(size-1)) break;
				//Otherwise reset the candidate point on that line
				curpt = pts[k];
				//Reset the counter and the flag
				cnt = 2;
				isline = false;
			}
		}
	}
}

//Getting the linesize vector
std::vector<int> Fast::getLineSize() {
	return linesize;
}

//Getting the linesize vector
std::vector<Point> Fast::getLinePoint() {
	return linepoint;
}