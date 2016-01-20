#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
Input: a list
Output: Return the two halves as different lists. 
*/

int
main(int argc, char** argv){
    string input(argv[1]);
    input.erase(std::remove(input.begin(), input.end(), ','), input.end());
    int half = input.length()/2;
    string lhs = input.substr(0,half);
    string rhs = input.substr(half);
    cout << lhs << endl << rhs << endl;
}