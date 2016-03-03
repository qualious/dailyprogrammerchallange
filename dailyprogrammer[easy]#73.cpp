#include <iostream>
#include <stack>
using namespace std;
/*
During the 70s and 80s, some handheld calculators used a very different notation
for arithmetic called Reverse Polish notation (RPN). Instead of putting operators
(+, *, -, etc.) between their operands (as in 3 + 4), they were placed behind
them: to calculate 3 + 4, you first inputted the operands (3 4) and then added
them together by pressing +.

Internally, this was implemented using a stack: whenever you enter a number, it's
pushed onto the stack, and whenever you enter an operator, the top two element
s are popped off for the calculation. Here's an example of a RPN calculator
calculating 3 4 * 6 2 - +:

[3] --> 3
[4] --> 3 4
[*] --> 12      ( 3 * 4 = 12)
[6] --> 12 6
[2] --> 12 6 2
[-] --> 12 4    ( 6 - 2 =  4)
[+] --> 16      (12 + 4 = 16)

Your task is to implement a program that reads a string in Reverse Polish notation
and prints the result of the calculation. Your program should support positive
and negative integers and the operators +, -, *.
*/

int
main(void){
    string solve = "3 4 * 6 2 - +";
    stack<int> v;
    for (size_t i = 0; i < solve.length(); i = i + 2) {
        if(isdigit(solve[i])){
            v.push(solve[i] - '0');
        }
        else{
            int y = v.top(); v.pop(); int x = v.top(); v.pop();
            cout << "x: " << x << "\ty: " << y << endl;
            if('+' == solve[i]) v.push(x + y);
            if('-' == solve[i]) v.push(x - y);
            if('*' == solve[i]) v.push(x * y);
        }
    }
    cout << v.top() << endl;
}
