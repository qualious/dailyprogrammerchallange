#include <iostream>
#include <algorithm>
using namespace std;
/*
Write a small program that can take a string:
"hi!"
and print all the possible permutations of the string:
"hi!"
"ih!"
"!hi"
"h!i"
"i!h"
etc...
*/

//such is life in <algorithm>
int
main(int argc, char** argv){
    string str(argv[1]);
    do
        cout << str << endl;
    while(next_permutation(str.begin(),str.end()));
}