#include <iostream>
using namespace std;
/*
Often times in commercials, phone numbers contain letters so that they're
easy to remember (e.g. 1-800-VERIZON). Write a program that will convert
a phone number that contains letters into a phone number with only numbers
and the appropriate dash.
Example Execution: Input: 1-800-COMCAST Output: 1-800-266-2278
*/
int
main(void){
    string input; int integer;
    cout << "Enter a phone number that contains letters" << endl;
    getline(cin, input);
    static const char keypad[27]="22233344455566677778889999";
    for(unsigned int i = 0; i < input.length(); ++i){
        if(isalpha(input[i])){
            integer = static_cast<int>(input[i]) - 65;
            input[i] = keypad[integer];
        }
    }
    cout << input.insert(9, "-") << endl;
}
