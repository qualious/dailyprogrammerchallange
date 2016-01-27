#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
/*
Write a function that takes two base-26 numbers in which digits 
are represented by letters with A=0, B=1, … Z=25 and returns 
their product using the same notation. As an example, CSGHJ × CBA = FNEUZJA.
Your task is to write the base-26 multiplication function.
*/

char
_result(char c1, char c2){
}

int
main(int argc, char** argv){                                                                
    char str[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
            'I','J', 'K', 'L', 'M', 'N', 'O', 'P','Q','R','S','T','U','V','W','X','Y','Z'};
    string s1(argv[1]); string s2(argv[2]); string s3;
    for (unsigned int i = 0; i < s2.length(); ++i){
        for (int j = 0; j < s1.length(); ++j){
            s3.push_back(str[((s1[j] - 'A') * (s2[i] - 'A'))%26]);
        }
    }
    cout << s3;
    
}