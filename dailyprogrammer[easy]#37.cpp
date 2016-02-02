#include <iostream>
#include <fstream>
using namespace std;
/*
write a program that takes
input : a file as an argument
output: counts the total number of lines. 
*/
int 
main(int argc, char** argv){
    ifstream file(argv[1]);
    string str;
    size_t lines = 0;               //using size_t for int since i learned the reason.
    while(getline(file, str)){
        ++lines;
        }
    cout << "lines: " << lines << endl;
}