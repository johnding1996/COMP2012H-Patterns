//The main cpp file for compiling the Fast program
#include <iostream>

#include "findline.h"

using namespace std;

//Main function
int main() {
	//Instance of findline
	FindLine fl;
	//Readind from the stdin
	fl.read(cin);
	//Running the fast find
	fl.fastFind();

	return 0;
}