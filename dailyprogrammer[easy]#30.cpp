#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Write a program that takes a list of integers and a target number 
and determines if any two integers in the list sum to the target number. 
If so, return the two numbers. If not, return an indication that no such 
integers exist.
*/

int
_min(vector<int>v,tn){
    int min = v[0];
    for(unsigned int i = 0; i < v.size(); ++i){
        if(v[i] < min)
        min = v[i];
    }
}

void
sum(vector<int>num, int tn){
    sort(num.begin(), num.end());
    int i = 0, rhs;
    while(rhs < tn){
        rhs = _min(num);
        rhs = rhs * rhs;
    }
    cout << rhs;
    for(unsigned int i = 0; i < num.size(); ++i){
        if(num[i] + num[num.size()] > 12)
            continue;
    }
}
int
main(void){
    vector<int>num;
    int tn, n;
    cout << "Enter a list: "; while(cin >> n && n != -1) num.push_back(n);
    cout << "Enter a target number: "; cin >> tn;
    sum(num,tn);
}