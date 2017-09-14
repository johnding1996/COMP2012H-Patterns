#include "point.h"

#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	if (argc<2) exit(0);

	ofstream input;
    input.open ("input.txt");
	srand (time(NULL));

	int repetition = atoi(argv[1]);
	int npl = 4;
	int npu = 5;
    if (argc>=3) npl = atoi(argv[2]);
    if (argc>=4) npu = atoi(argv[3]);
	int x0, y0, dx, dy;
	int size = (npl+npu)*(npu-npl+1)*repetition/2;
	input << size << endl;
	Point ps[size];
	int cnt = 0;
	for (int k=0; k<repetition; ++k) {
		for (int j=npl; j<=npu; ++j) {
			x0 = rand()%1000;
			y0 = rand()%1000;
			dx = rand()%1000;
			dy = rand()%1000;
			for (int i=0; i<j; ++i) {
				ps[cnt].setCoor(x0+i*dx,y0+i*dy);
				input << x0+i*dx << ' ' << y0+i*dy << endl;
				++cnt;
			}
		}
	}
	input.close();
	return 0;
}