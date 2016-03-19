#include <iostream>
#include <map>
using namespace std;
/*
   Run-Length encoding is a simple form of compression that
   detects 'runs' of repeated instances of a symbol in a
   string and compresses them to a list of pairs of 'symbol'
   'length'. For example, the string
   "Heeeeelllllooooo nurse!"
   Could be compressed using run-length encoding to the list
   of pairs [(1,'H'),(5,'e'),(5,'l'),(5,'o'),(1,'n'),(1,'u'),(1,'r'),(1,'s'),(1,'e')]

*/
int
main(void){
    string s = "Heeeeelllllooooo nurse!";
    size_t zip[10] = {0}, j=0;
    char prevChar = ' ';
    for(size_t i = 0; i < s.length(); ++i){
        if(s[i] == prevChar){
            ++zip[j];
        }else{
            ++j;
            ++zip[j];
        }
        prevChar = s[i];
    }
}
