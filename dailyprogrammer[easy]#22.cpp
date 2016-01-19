#include <iostream>
using namespace std;
/*
Write a program that will compare two lists, 
and append any elements in the second list that doesn't exist in the first.
input: ["a","b","c",1,4,], ["a", "x", 34, "4"]
output: ["a", "b", "c",1,4,"x",34, "4"]
*/

//since lists don't exist in C++, i assume that they are strings and items
//are seperated with a comma. 

int
main(int argc, char** argv){
    string s1(argv[1]); string s2(argv[2]);
    cout << s1 << ","; 
    for(unsigned int i = 0; i < s2.length(); ++i){
        int found = s1.find(s2[i]);
        if(found == -1){
            if(i != s2.length()-1)
                cout << s2[i] << ",";
            else 
                cout << s2[i];
        }
    }
}