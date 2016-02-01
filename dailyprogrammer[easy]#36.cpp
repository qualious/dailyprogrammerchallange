#include <iostream>
#include <cmath>
using namespace std;
#define LOCK_NUM 1000
/*
In an high school there exist 1000 lockers labelled 1, 2, ..., 1000. 
All of them are closed. 1000 students are to "toggle" a locker's state.
* The first student toggles all of them * 
The second one toggles every other one (i.e, 2, 4, 6, ...) * 
The third one toggles the multiples of 3 (3, 6, 9, ...) and so on until all students have finished.
To toggle means to close the locker if it is open, and to open it if it's closed.
How many and which lockers are open in the end?
*/

//solution from http://www.algebra.com/algebra/homework/Graphs/Graphs.faq.question.72342.html
int
main(void){
    unsigned int count = 0;
    int n, i = 1;
    while(n < LOCK_NUM){
        n = pow(i,2);
        i++;
        count++;
    }

    cout << --count << " lockers is open in the end" << endl;
}