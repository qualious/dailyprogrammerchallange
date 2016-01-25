#include <iostream>
#include <algorithm>
using namespace std;
/*
A Palindrome is a sequence that is the same in reverse as it is forward.
I.e. hannah, 12321.
Your task is to write a function to determine whether a given string is palindromic or not.
*/
int
main(int argc, char** argv){
    string input(argv[1]);
    string lhs = input.substr(0,input.length()/2);
    string rhs = input.substr(input.length()/2);
    if(rhs.length() - lhs.length())
        rhs = input.substr(input.length()/2+1);
    cout << "LHS: " << lhs << endl << "RHS: " << rhs << endl; 
    reverse(rhs.begin(), rhs.end());
    if(lhs == rhs){
        cout << "Palindrome!\n";
    }else
        cout << "Non-palindrome!\n";
}