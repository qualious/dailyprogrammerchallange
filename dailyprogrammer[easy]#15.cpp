#include <iostream>
#include <iomanip>
using namespace std;
//Write a program to left or right justify a text file

int
main(void){
    string justify;
    cout << "What way do you want to justify the text ?(r/l)" << endl;
    getline(cin, justify);
    string input;
    cout << "Enter the text that you want to justify" << endl;
    getline(cin, input);
    if(justify == "r"){
        cout << right << setw(13) << input << endl;
    }
    else{
       cout << left << setw(13) << input << endl;
    }
}