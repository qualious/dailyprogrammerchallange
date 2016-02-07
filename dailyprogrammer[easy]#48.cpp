#include <iostream>
#include <vector>
using namespace std;
/*
Take an array of integers and partition it so that all
the even integers in the array precede all the odd
integers in the array. Your solution must take linear
time in the size of the array and operate in-place with
only a constant amount of extra space.
*/

void
printVec(const std::vector<int>& vec){
    for(auto x: vec){
         cout << ' ' << x;
    }
    cout << '\n';
}

int
main(void){
    vector<int>arr;
    arr.push_back(1);
    int num;
    int i = 0;
    cout << "Enter an array of integers\n";
    while(cin.good()){
        cin >> num;
        if((num%2) == 0 && arr[i]%2 == 0)           //even
            arr.push_back(num);
        else
            arr.insert(arr.end()-1,num);
        ++i;
    }
    printVec(arr);
}
