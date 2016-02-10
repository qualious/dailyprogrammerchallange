#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
   Write a program that given an array A and a number N, generates all combinations
   of items in A of length N.

   That is, if you are given the array [1,2,3,4,5] and 3, you're supposed to generate

    [1,2,3]
    [1,2,4]
    [1,2,5]
    [1,3,4]
    [1,3,5]
    [1,4,5]
    [2,3,4]
    [2,3,5]
    [2,4,5]
    [3,4,5]
 */
void
print(vector<size_t> v){
    for(auto x: v)
        cout << " " << x;
    cout << endl;
}

void
findSubset(size_t arr[], size_t num, size_t left, size_t index, vector<size_t> &v){
    if(!left) {
        print(v);
        return;
    }
    for(size_t i = index; i < num; ++i) {
        v.push_back(arr[i]);
        findSubset(arr,num,left-1,i+1,v);
        v.pop_back();
    }
}

int
main(void){
    size_t array[5]={1,2,3,4,5};
    vector<size_t>v;
    findSubset(array,5,3,0,v);
}
