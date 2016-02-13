#include <iostream>
#include <vector>
using namespace std;
/*
   Write a program to solve the sliding window minimum problem using any of the
   methods possible. This could be a helpful link.
   Let A[] is an array of integers and integer K -- window size. Generate array
   M of minimums seen in a window as it slides over A
 */

void
slidingWindowMin(vector<int> v, int k){
    for (size_t i = 0; i < v.size()-(k-1); ++i) {
        vector<int>sub(&v[i],&v[i+k]);
        int min = sub[0];
        for (int j = 1; j < k; ++j) {
            if(sub[j] < min)
                min = sub[j];
        }
        cout << min << " ";
    }
}

int
main(void){
    std::vector<int> v = {1,3,0,-3,5,3,6,7,8}; int k = 3;
    slidingWindowMin(v,k);
}
