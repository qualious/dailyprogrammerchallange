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

int
main(int argc, char** argv){                                                                
    char str[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
            'I','J', 'K', 'L', 'M', 'N', 'O', 'P','Q','R','S','T','U','V','W','X','Y','Z'};
    string s1(argv[1]); string s2(argv[2]); string s3, s4,s5;
    long int a = 0;
    for (unsigned int i = 0; i < s2.length(); ++i){
        for (int j = 0; j < s1.length(); ++j){
            s3.push_back(str[((s1[j] - 'A') * (s2[i] - 'A'))%26]);
        }
    }
    for(unsigned int i = s2.length() * s1.length(); i > 0; i = i - s1.length()){
        s4 = s3.substr(i-s1.length(),i);
        if(s4.length() > s1.length())
            s4 = s4.substr(0,s1.length());
        for (unsigned int j = 0; j < s4.length(); ++j){
            a *= 10;
            a += s4[j] - 'A';
            cout << static_cast<char>(a%10 + 65);
        }
    }
}