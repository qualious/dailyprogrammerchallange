#include <iostream>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;
/*
Input: A sequence of integers either +ve or -ve
Output : a part of the sequence in the list with the maximum sum.
*/
void
print(vector<int> v){
    for(auto x: v)
        cout << x << ' ';
    cout << endl;
}
int
maxAt(std::vector<int>& v) {
    int max = v[0];
    for (auto val : v) {
         if (max < val) max = val;
    }
    return max;
}

int
findMax(vector<int> v){
    int max = maxAt(v);
    for (size_t i = 0; i < v.size(); ++i) {
        if(max == v[i])
            return i;
    }
    return -1;
}
int
main(void){
    vector<int> v = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    vector<int> sums;
    size_t w = 1;       //window size
    while(w != v.size()){
        for (size_t i = 0; i < v.size()-(w-1); ++i) {
            vector<int>sub(&v[i],&v[i+w]);
            size_t sum = 0;
            for (size_t j = 1; j < w; ++j)
                sum += sub[j];
            sums.push_back(sum);
        }
        ++w;
    }
    int m = findMax(sums);
    cout << sums[m];
}
