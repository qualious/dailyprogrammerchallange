#include <iostream>
using namespace std;
/*
keytochar(key='a',caps=True) = 'A'
keytochar(key='a',caps=True,shift=True) = 'a'
boolean ctrl alt shift capslock
*/

void
keytochar(char ch,bool caps,bool shift,bool alt,bool capslock){
    if(capslock && shift)
        cout << ch << endl;
    else if(!capslock)
        cout << toupper(ch) << endl;
    else if(!shift)
        cout << toupper(ch) << endl;
    else
        cout << ch << endl;
}

int
main(void){
    char ch = 'a';
    bool caps = false, shift = false, alt = false, capslock = false;
    keytochar(ch,caps,shift,alt,capslock);
}
