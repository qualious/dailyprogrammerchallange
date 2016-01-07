#include <iostream>
#include <string.h>
using namespace std;
/*
The exercise today asks you to validate a telephone number, as if written on an input form. Telephone numbers can be written as ten digits, or with dashes, spaces, or dots between the three segments, 
or with the area code parenthesized; both the area code and any white space between segments are optional.
The following are valid telephone numbers: 
1234567890, 123-456-7890, 123.456.7890, (123)456-7890, (123) 456-7890 456-7890.
The following are not valid telephone numbers: 
123-45-6789, 123:4567890, and 123/456-7890.
source: programmingpraxis.com
*/

int 
main(void){
    cout << "Enter a phone number: " << endl;
    string input;   int i = 0;
    getline(cin, input);                                    //getline because spaces
    for(unsigned int i = 0; i< input.length(); ++i){
        if(input[i] - '0' <= 9 && input[i] - '0' >= 0)       //if number
            input[i] = 'x';                                 //replace with x
    }
    if(!strcmp(input.c_str(),"xxx-xxx-xxxx"))
        cout << "Valid";
    else if(!strcmp(input.c_str(),"xxxxxxxxxx"))
        cout << "Valid";
    else if(!strcmp(input.c_str(),"xxx.xxx.xxxx"))
        cout << "Valid";
    else if(!strcmp(input.c_str(),"(xxx)xxx-xxxx"))
        cout << "Valid";
    else if(!strcmp(input.c_str(),"(xxx) xxx-xxxx"))
        cout << "Valid" << endl;
    else 
        cout << "Invalid" << endl;

}