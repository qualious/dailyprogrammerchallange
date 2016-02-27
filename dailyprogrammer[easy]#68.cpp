#include <iostream>
#include <algorithm>
using namespace std;
/*
   Your task is to implement a function which prints out the emirps below a
   number(input) given by the user.
 */
bool
isPalindrome(string input){
    string lhs = input.substr(0,input.length()/2);
    string rhs = input.substr(input.length()/2);
    if(rhs.length() - lhs.length())
        rhs = input.substr(input.length()/2+1);
    reverse(rhs.begin(), rhs.end());
    if(lhs == rhs){
        return true;
    }else
        return false;
}
bool
isPrime(string input){
    int intput = stoi(input);
    for(unsigned int j = 3; j < intput ; j += 2){
        if(!(intput%j))
            return false;
    return true;
    }
}
int
main(void){
    string n = "14";
    if(!isPalindrome(n) && isPrime(n))
        cout << "Emirp!" << endl;
    else
        cout << "That is not an emirp!" << endl;
}
