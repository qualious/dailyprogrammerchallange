// find_missing(
//  [4, 8, 12, 9, 3, 90]
//  [4, 8, 12, 6, 90, 9, 3]
//  } => 12

#include<iostream>

void
find_difference(int* a, int a_len, int* b, int b_len) {
    
    int c = 0; 
    for(int i = 0; i < a_len; ++i) {
        c ^= a[i];
    }

    int d = 0;
    for(int i = 0; i < b_len; ++i) {
        d ^= b[i];
    }

    int result = c ^ d;
    std::cout << "Missing value is: " << result << std::endl; 
}

int
main(void) {
    int a[] = {4, 8, 12, 9, 3, 90};
    int b[] = {4, 8, 12, 6, 90, 9, 3};
    find_difference(a, (sizeof(a)/sizeof(*a)), b, (sizeof(b)/sizeof(*b)));
}

