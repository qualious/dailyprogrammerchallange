#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
   Give the Ullman's Puzzle
   Write a function that makes that determination

   Given a list of n real numbers, a real number t, and an integer k, determine
   if there exists a k-element subset of the original list of n real numbers that
   is less than t.

   For instance, given the list of 25 real numbers

   18.1, 55.1, 91.2, 74.6, 73.0, 85.9, 73.9, 81.4, 87.1, 49.3, 88.8, 5.7, 26.3, 7.1,
   58.2, 31.7, 5.8, 76.9, 16.5, 8.1, 48.3, 6.8, 92.4, 83.0, 19.6,

   t = 98.2 and k = 3, the 3-element subset 31.7, 16.5 and 19.6 sums to 67.8,
   which is less than 98.2, so the result is true.
 */
int
main(void){
    vector<double> n = {18.1, 55.1, 91.2, 74.6, 73.0, 85.9, 73.9, 81.4, 87.1, 49.3, 88.8, 5.7, 26.3, 7.1,
        58.2, 31.7, 5.8, 76.9, 16.5, 8.1, 48.3, 6.8, 92.4, 83.0, 19.6 };
    double t = 98.2, k = 3;
    sort(n.begin(), n.end());
    while(k > 0)
        t -= n[--k];
    if(t >= 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
