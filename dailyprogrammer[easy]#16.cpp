#include <iostream>
using namespace std;
/*
Write a function that takes two strings and removes from the first string
any character that appears in the second string. For instance, if the first
string is “Daily Programmer” and the second string is “aeiou ” the result is
“DlyPrgrmmr”. note: the second string has [space] so the space between 
"Daily Programmer" is removed
*/

int
main(void){
    string input, del;
    cout << "Enter the first string. \n";
    getline(cin, input);
    cout << "Enter the second string. \n";
    getline(cin, del);

    int found = input.find_first_of(del);
    while (found != -1){
        input[found] ='\0';
        found = input.find_first_of(del,found+1);
    }
    cout << input << endl;
}