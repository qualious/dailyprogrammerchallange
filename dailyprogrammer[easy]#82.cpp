#include <iostream>
using namespace std;
/*
   Write a function that takes a number n as an argument and returns (or outputs)
   every possible unique substrings (not counting "") of the first n letters of
   the alphabet (in any order you like). For example, substrings(5) could be:

   a
   ab
   abc
   abcd
   abcde
   b
   bc
   bcd
   bcde
   c
   cd
   cde
   d
   de
   e
   BONUS 1: Find a way to quickly determine how many strings this function
   returns for a given input. If the alphabet were 500 letters long, how much
   possible substrings would it have?
   BONUS 2: Modify your function to take a string as an argument. Make sure all
   substrings in your output are still unique (i.e., there are two "l" substrings
   in "hello", but you should output only one).
 */
int
main(void){
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K' ,'L','M','N', 'O', 'P', 'Q', 'R', 'S','T', 'U','V','W','X','Y','Z'};          //bonus 2 would be making this a given string.
    size_t n = 5, k = 0, count = 0;
    while(k < n){
        for (size_t i = k; i < n; ++i) {
            for (size_t j = k; j <= i; ++j) {
                cout << alphabet[j];
                ++count;                //bonus 1
            }
            cout << endl;
        }
        ++k;
    }
}
