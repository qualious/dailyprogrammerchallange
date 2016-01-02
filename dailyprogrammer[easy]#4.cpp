#include <iostream>
#include <cstdlib>                  //srand and rand
#include <sstream>                  //to get strangstream
//#include <unistd.h>               //unix sleep  
using namespace std;
/*
You're challenge for today is to create a random password generator!
For extra credit, allow the user to specify the amount of passwords to generate.
For even more extra credit, allow the user to specify the length of the strings 
he wants to generate!
*/
//65 to 122 ascii
inline void
getRandomPass(int pLen){
    int rand_num; 
    string password = "";
    stringstream out;
    for(int i = 0; i < pLen; ++i){
        rand_num = rand()%57+65;           
        out << static_cast<char>(rand_num);
        password = out.str();
        //snprintf(password, sizeof(password), "%d", rand_num);         //the C way
    }
    cout << password << endl;
}


int
main(void){
    srand(time(NULL));              //used here, not in the getRandomPass to avoid dublicates
    int pCount, pLen;
    cout << "How many password to generate ?" << endl;
    cin >> pCount;
    cout << "Lenght of password(s) to generate ?" << endl;
    cin >> pLen;
    for(int i = 0; i < pCount; ++i){
        getRandomPass(pLen);
    }
}
