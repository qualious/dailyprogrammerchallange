#include <iostream>
using namespace std;
#define MAX 1000
/*
Print the numbers from 1 to 1000 without using any loop or conditional statements.
Don’t just write the printf() or cout statement 1000 times.
Be creative and try to find the most efficient way!
*/
void
printNums(int i){
    cout << i << endl; 
    int floatingPointError = 1 / (MAX - i);
    return printNums(++i);
}

int
main(void){
    printNums(1);
}