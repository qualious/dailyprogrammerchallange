#include <iostream>
using namespace std;
/*
you have a string "ddaaiillyypprrooggrraammeerr". We want to remove all the 
consecutive duplicates and put them in a separate string, which yields two 
separate instances of the string "dailyprogramer".
use this list for testing:
input: "balloons"
expected output: "balons" "lo"
input: "ddaaiillyypprrooggrraammeerr"
expected output: "dailyprogramer" "dailyprogramer"
*/

int 
main(int argc, char** argv){
    string input(argv[1]);
    string dublicates;
    for(unsigned int i = 0; i < input.length(); ++i)
        if(input[i] == input[i+1])
            dublicates.push_back(input[i+1]);
    for(unsigned int i = 0; i < input.length(); i = i+2){
        for(unsigned int j = 0; j < dublicates.length(); ++j)
            if(input[i] == dublicates[j]){
                input[i] = NULL;
        }
    }
    cout << input << endl << dublicates << endl;
}