//The main cpp file for compiling the Brute program
#include <iostream>

#include "findline.h"

using namespace std;

//Main function
int main() {
	//Instance of findline
	FindLine fl;
	//Readind from the stdin
	fl.read(cin);
	//Running the brute find
	fl.bruteFind();

	return 0;
}