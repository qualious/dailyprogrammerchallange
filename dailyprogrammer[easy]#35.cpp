#include <iostream>
using namespace std;
/*
Write a program that will take a number and print a right triangle attempting to use all numbers from 1 to that number.
Sample Run:
Enter number: 10
Output:
7 8 9 10
4 5 6
2 3
1
*/

int eSum(int n){
    int sum = 0;
    for(unsigned int i = 0; i < n; ++i){
        sum += i;
    }
    return sum;
}

int
calculateDiagonal(const int n){
    int diagonal = -1;
    for(unsigned int i = 1; eSum(i) <= n; ++i){
        diagonal++;
    }
    return diagonal;
}

void
drawTriangle(const int diagonal){
    for(unsigned int i = diagonal; i >= 1 ; --i){
        for(unsigned int j = 1 + eSum(i); j <= i + eSum(i); ++j){
            cout << j << " ";
        }
        cout << endl;
    }
}

int 
main(void){
    cout << "Enter a number to make a right triangle : ";
    int n;
    cin >> n;
    int diagonal = calculateDiagonal(n);
    //cout << diagonal << endl;
    drawTriangle(diagonal);
}