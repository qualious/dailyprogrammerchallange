#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
write a program that will allow the user to input digits, 
and arrange them in numerical order.
for extra credit, have it also arrange strings in alphabetical order
*/
void 
Print(const vector<int>& num){
    for(unsigned int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
}

int 
main(void){
    vector<int> num; int i = 0; int n;
    cout << "Enter numbers to get it sorted. To abort, "
                 "enter anything other than a number" << endl;
    while(true){
        cin >> n;
        if(cin.good()){
            num.push_back(n);
            ++i;
        }
        else break;
    }
    sort(num.begin(), num.end());
    Print(num);
}