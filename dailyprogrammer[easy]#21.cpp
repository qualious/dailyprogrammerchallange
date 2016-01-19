#include <iostream>
#include <algorithm>
using namespace std;
/*
Input: a number
Output : the next higher number that uses the same set of digits.
*/

int
returnIndex(string s){
    for(unsigned int i = s.length(); i > 0; --i){
        if(s[i] < s[i-1])
            continue;
        else{
            return i;             //stopped being in decreasing order.
        }
    }
    return -1;
}

int
findSmallest(string s, int n){
    int min = s[0];    
    for(unsigned int i = 1; i < s.length(); ++i){
        if(s[i] < min)
            min = s[i];
            if(min > n)
                return min;
    }
}

int
main(int argc, char** argv){
    string input(argv[1]);
    int index = returnIndex(input);
    if(index == -1){
        cout << "Don't ask me impossible things fam, exiting..." << endl;
        return -1;
    }
    string lhs = input.substr(0,index);
    string rhs = input.substr(index);
    int rhsMin = findSmallest(rhs, static_cast<int>(lhs[index]));
    int rhsIndex = rhs.find(rhsMin);
    char temp;
    temp = rhs[rhsIndex];
    rhs[rhsIndex] = lhs[index - 1];
    lhs[index - 1] = temp;
    sort(rhs.begin(), rhs.end());
    cout << input << " --> " << lhs << rhs << endl;
}