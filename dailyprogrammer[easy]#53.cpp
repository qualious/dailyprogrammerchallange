#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
   Write a function that given two sorted lists, returns a list whith the two lists
   merged together into one sorted list.
   So, for instance, for inputs [1,5,7,8] and [2,3,4,7,9] it should return
   [1,2,3,4,5,7,7,8,9].
   Try and make your code as efficient as possible.
*/

void
print(vector<size_t> v){
    for(auto x: v)
        cout << x << ' ';
    cout << endl;
}

int
main(void){
    size_t v1[] = {1,5,7,8};
    size_t v2[] = {2,3,4,7,9};
    vector<size_t> merged(10);
    //(sizeof(v1)/sizeof(*v1)) = lenght of the array. Can't live  with hardcoded code.
    merge(v1,v1+(sizeof(v1)/sizeof(*v1)),v2,v2+(sizeof(v2)/sizeof(*v2)),merged.begin());
    print(merged);
}
