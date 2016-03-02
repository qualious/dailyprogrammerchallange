#include <iostream>
#include <map>
using namespace std;
/*
   The one-dimensional simple cellular automata Rule 110 is the only such cellular
   automata currently known to be turing-complete, and many people say it is the
   simplest known turing-complete system.

   Implement a program capable of outputting an ascii-art representation of applying
   Rule 110 to some initial state. How many iterations and what your initial state
   is is up to you!

   You may chose to implement rule 124 instead if you like (which is the same thing,
   albeit backwards).

   current pattern 	           111 110 101 100 011 010 001 000
   new state for center cell 	0 	1 	1 	0 	1 	1 	1 	0
 */
inline void
drawAscii(size_t n){
    if(n == 1)
        cout << "*";
    else
        cout << " ";
}

int
main(void){
    map<string,size_t> rules =  {{"111", 0}, {"110",1}, {"101",1},{"100",0},
                                {"011",1},{"010",1},{"001",1}, {"000",0}};
    string s = "0110101110101";
    string sub;
    for (size_t i = 0; i < s.length(); ++i) {
        if(i == 0){
            sub = "0" + s.substr(i,i+2);
            drawAscii(rules.at(sub));
        }else if(i == s.length() - 1){
            sub = s.substr(i-1,3) + "0";
            drawAscii(rules.at(sub));
        }else{
            sub = s.substr(i-1,3);
            drawAscii(rules.at(sub));
        }
    }
    cout << endl;
}
