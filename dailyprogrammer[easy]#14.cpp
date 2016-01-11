#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
Input: list of elements and a block size k or some other variable of your choice
Output: return the list of elements with every block of k elements reversed, 
starting from the beginning of the list.
For instance, given the list 12, 24, 32, 44, 55, 66 and the block size 2, 
the result is 24, 12, 44, 32, 66, 55.
*/
void 
Print(const deque<int>& num){
    for(unsigned int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
}

int
main(void){
    deque<int>elements;
    deque<int>subElements;
    int blockSize, n;
    cout << "Please enter a list of integers, enter -1 to quit entering input" << endl;
    while(true){
        cin >> n;
        if(cin.good() && n != -1){
            elements.push_back(n);
        }
        else break;
    }
    cout << "Please enter a the block size to reverse array in that block" << endl;
    cin >> blockSize;
    for(unsigned int j = 0; j < elements.size()/blockSize; ++j){
        reverse(elements.begin(), elements.end());
        for(unsigned int i = 0; i < blockSize; ++i){
            subElements.push_back(elements[i]);
        }
        for(unsigned int i = 0; i < blockSize; ++i){
            elements.pop_front();
        }
    }
}