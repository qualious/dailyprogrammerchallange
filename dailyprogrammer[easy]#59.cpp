#include <iostream>
#include <string>
using namespace std;
/*
   Write a program that given two strings, finds out if the second string is
   contained in the first, and if it is, where it is.

   I.e. given the strings "Double, double, toil and trouble" and "il an" will
   return 18, because the second substring is embedded in the first, starting on
   position 18.

   NOTE: Pretty much every language have this functionality built in for their
   strings, sometimes called find() (as in Python) or indexOf() (as in Java). But
   the point of this problem is to write the program yourself, so you are not
   allowed to use functions like this!
 */
ptrdiff_t
findS(string s1, string s2){
    for (size_t i = 0; i + s2.length() < s1.length(); ++i) {
        string sub = s1.substr(i, s2.length());
        if(sub.compare(s2) == 0)
            return i;
    }
    return -1;
}

int
main(void){
    string s1 = "Double, double, toil and trouble", s2 = "il an";
    ptrdiff_t pos = findS(s1,s2);
    cout << pos << endl;
}
