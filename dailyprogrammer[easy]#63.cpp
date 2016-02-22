#include <iostream>
#include <vector>
using namespace std;
/*
   Write a procedure called reverse(N, A), where N is an integer and A is an array
   which reverses the N first items in the array and leaves the rest intact.

   For instance, if N = 3 and A = [1,2,3,4,5], then reverse(N,A) will modify A so
   that it becomes [3,2,1,4,5], because the three first items, [1,2,3], have been
   reversed.
*/

void
print(vector<size_t> v){
    for(auto x: v)
        cout << x;
    cout << endl;
}

vector<size_t>
reverse(vector<size_t> v, size_t n){
    vector<size_t> r;
    for (size_t i = (n-1); i > 0; --i) {
        r.push_back(v[i]);
    }
    r.push_back(v[0]);
    for (size_t i = n; i < v.size(); i++) {
        r.push_back(v[i]);
    }
    return r;
}

int
main(void){
    vector<size_t> v = {1,2,3,4,5}; size_t n = 4;
    std::vector<size_t> r = reverse(v, n);
    print(r);
}
