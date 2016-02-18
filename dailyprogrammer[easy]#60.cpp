#include <iostream>
using namespace std;
/*
   A polite number n is an integer that is the sum of two or more consecutive
   nonnegative integers in at least one way.
   Here is an article helping in understanding Polite numbers
   Your challenge is to write a function to determine the ways if a number is
   polite or not.
 */

bool
isPolite(size_t num){
    if(num%2){      //if odd
        if(num == 1)
            return false;
        else true;
    }
    else{
        if(num == num / 2 + num / 2 - 1)
            return true;
        else false;
    }

}

int
main(void){
    size_t num;
    cout << "Enter a number to check whether or not it is polite: ";
    cin >> num;
    cout << isPolite(num);
}
