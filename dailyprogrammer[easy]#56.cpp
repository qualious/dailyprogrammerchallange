#include <iostream>
using namespace std;
/*
   The ABACABA sequence is defined as follows: start with the first letter of the
   alphabet ("a"). This is the first iteration. The second iteration, you take the
   second letter ("b") and surround it with all of the first iteration
   (just "a" in this case). Do this for each iteration, i.e. take two copies of the
   previous iteration and sandwich them around the next letter of the alphabet.

   Here are the first 5 items in the sequence:

   a
   a 'b' a
   aba 'c' aba
   abacaba 'd' abacaba
   abacabadabacaba 'e' abacabadabacaba

   And it goes on and on like that, until you get to the 26th iteration
   (i.e. the one that adds the "z"). If you use one byte for each character, the
   final iteration takes up just under 64 megabytes of space.

   Write a computer program that prints the 26th iteration of this sequence to a file.
 */

void
naiveSolution(void){
    string s1("a");
    for (size_t i = 1; i <= 6; ++i) {
        string prevs1 = s1;
        // if(i == 26)
            cout << "i : " << i  << "\t" << s1 << "\t\n";
        s1.push_back(('a' + i));
        s1 += prevs1;
    }
}


char
wctu(size_t i){  //which char to use
    if(!(i%2))  //if odd
        return 'a';
    else{
        size_t j = 0;
        for(j = 0; (i%2) ; ++j) {
            i>>=1;          //Meaning, how many times does it take to make it odd.
        }                   // 2^1 = 2 = b,  000010 -> 000001, 1 times -> return b;
                            // 2^2 = 4 = c,  000100 -> 000001, 2 times -> return c;
                            // 2^3 = 8 = d,  001000 -> 000001, 3 times -> return d;
                            // 2^4 = 16 = e, 010000 -> 000001, 4 times -> return e;
                            // 2^5 = 32 = f, 100000 -> 000001, 5 times -> return f;
        return static_cast<char>(j+97);
    }

}

void
efficentSolution(void){             //i hope it is efficent
    size_t k = 1;
    for (size_t i = 0; i < (1<<26); ++i) {   //1<<26;
        char c = wctu(i);
        cout << c;
    }
}

int
main(void){
    //naiveSolution();
    efficentSolution();
}
