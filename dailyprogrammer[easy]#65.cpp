#include <iostream>
#include <vector>
using namespace std;
/*
   Write a program that given a floating point number, gives the number of American
   dollar coins and bills needed to represent that number (rounded to the nearest
   1/100, i.e. the nearest penny). For instance, if the float is 12.33, the result
   would be 1 ten-dollar bill, 2 one-dollar bills, 1 quarter, 1 nickel and 3 pennies.

   For the purposes of this problem, these are the different denominations of the
   currency and their values:

    Penny: 1 cent
    Nickel: 5 cent
    Dime: 10 cent
    Quarter: 25 cent
    One-dollar bill
    Five-dollar bill
    Ten-dollar bill
    Fifty-dollar bill
    Hundred-dollar bill

   Sorry Thomas Jefferson, JFK and Sacagawea, but no two-dollar bills, half-dollars
   or dollar coins!

   Your program can return the result in whatever format it wants, but I recommend
   just returning a list giving the number each coin or bill needed to make up the
   change. So, for instance, 12.33 could return [0,0,1,0,2,1,0,1,3] (here the
   denominations are ordered from most valuable, the hundred-dollar bill, to least
   valuable, the penny)
 */
int
main(void){
    ptrdiff_t sheckel = 12.33 * 100;       //multiply it by 100 in order to rounditup
    vector<ptrdiff_t> moneh = {10000,5000,1000,500,100,25,10,5,1};
    size_t count = 0;
    for (size_t i = 0; i < moneh.size(); ++i) {
        if(sheckel > moneh[i]){
            while(sheckel - moneh[i] > 0){
                ++count;
                sheckel -= moneh[i];
            }
        }
        if(moneh[i] == 1)
            ++count;
        cout << count << ' ';
        count = 0;
    }
}
