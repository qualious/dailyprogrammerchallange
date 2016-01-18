#include <iostream>
using namespace std;
//create a program that will find all prime numbers below 2000

int 
main(){
    cout << "2" << endl;
    bool prime = true;
    for(unsigned int i = 3; i < 2000; i += 2){
        prime = true;
        for(unsigned int j = 3; j < i; j += 2){
            if(!(i%j)){
                prime = false;
                break;
            }
        }
        if(prime) 
            cout << i << endl;
    }
}
