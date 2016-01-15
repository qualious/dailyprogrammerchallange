#include <iostream>
using namespace std;
/*
write an application which will print a triangle of stars of user-specified
height, with each line having twice as many stars as the last. sample output:
@      
@@    
@@@@   
*/
int 
main() {
    int height;
    cout << "Enter a height" << endl;
    cin >> height;
    int j = 1;
    for(unsigned int i = 1; i <= height; ++i){
        for(int k = 0; k < j; ++k)
            cout << '@';
        j *= 2;
        cout << '\n';
    }
}