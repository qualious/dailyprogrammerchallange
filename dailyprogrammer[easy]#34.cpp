#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
/*
input is are : 3 numbers as arguments
output: the sum of the squares of the two larger numbers.
*/
int
findSmallest(int k, int l, int m){
    int min = k;
    if(min > l)
        min = l;
    if(min > m)
        min = m;
    return min;
}

bool 
is_digit(const string &str){
    return str.find_first_not_of("0123456789") == string::npos;
}

int 
main(int argc, char** argv){
    if(!is_digit(argv[1]) || !is_digit(argv[2]) || !is_digit(argv[3])){
        cout << "You must enter integers, quiting..\n";
        return EXIT_FAILURE;
    }
    long n1 = atoi(argv[1]), n2 = atoi(argv[2]), n3 = atoi(argv[3]);
    int min = findSmallest(n1,n2,n3);
    if(n1 == min)
        cout << pow(n2,2) + pow(n3,2) << endl;
    else if(n2 == min)
        cout << pow(n2,2) + pow(n3,2) << endl;       
    else if(n3 == min){
        cout << pow(n2,2) + pow(n3,2) << endl;}
    return EXIT_SUCCESS;
}