# Pattern Recognition
Project 4 for COMP2012H, 2016 Fall, HKUST

A simple pattern recognition program

  
## How-to-compile-and-run
```
$ make
$ ./bin/PointPlotter
$ ./bin/Fast
$ ./bin/Brute
```

## Q&A
```
/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
The brute force algorithm is implemented by nesting four for loops to traverse every combinations of four distinct points and check whether they are coline. If they are coline, outpot the result to the command line and store the results to a vector

Auxilary methods in Point:
bool coline(Point&, Point&, Point&): Check whether four points are coline.
bool operator== (const Point&) const: Overloading the operator== to check whether the slope are equal.

/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
The sorting solution is implemented by sorting the relative slope to a selected origion and check the possible lines by travering the sorted points. Generally, we need to select each point as origion and in order to avoid repetition, we check whether the new lines contain the old points each time.

Auxilary methods in Point:
double angle(Point&): calculate the slope and store them in Point data type later to be sorted.
bool operator< (const Point&) const: Overloading the operator< to define the order for sort(). 

To ensure the representation is minimum, each time the program find a new line, it checks whether it contains the points that have already been tested. If it is, the line must have been outputted before, so just do not record and output it.


/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10       0.00        0.00
     20       0.00        0.00
     40       0.00        0.00
     80       0.00        0.00
    100       0.02        0.00
    150       0.10        0.00
    200       0.38        0.01
    400       6.34        0.04
   1000       98.45       0.12
   2000       N/A         0.54
   4000       N/A         2.34
  10000       N/A         16.60



/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute: 1*10^14s
Sorting: 3*10^5s



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute: O(N^4)
Sorting: O(N^2*log(N))

Brute: There are O(N^4) different combinations by combinatorics.
Sorting: Each sorting use O(N*log(N)) worst-time (the implementation of c++ STL algorithm can achieve this) and there are N of them.

/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
No critical bugs or limitations found.


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
No serious problem found.



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
The GUI part is not quite relevant to the whole problem.
```
