#include <iostream>
#include <vector>
using namespace std;
/*
   Write a function that takes two arguments, x and y, which are two strings
   containing Roman Numerals without prefix subtraction (so for instance, 14 is
   represented as XIIII, not XIV). The function must return true if and only if
   the number represented by x is less than the number represented by y. Do it
   without actually converting the Roman numerals into regular numbers.

   Challenge: handle prefix subtraction as well.
 */

inline size_t
score(char x){
    vector<char> roman = {'I' , 'V', 'X', 'L', 'C', 'D', 'M'};
    for (size_t i = 0; i < roman.size(); ++i) {
        if(roman[i] == x)
        return i;
    }
}

bool
xlessthany(string x, string y){
    size_t xscore = 0, yscore = 0;
    for (size_t i = 0; i < x.length(); ++i) {
        xscore += score(x[i]);
        yscore += score(y[i]);
    }
    return xscore < yscore;
}

int
main(void){
    string x = "X";
    string y = "VIIII";
    cout << boolalpha << "X less than Y ? " << xlessthany(x,y) << endl;
}
