#include <iostream>
#include <vector>
using namespace std;
/*
   Here's a table summarizing the words for different numbers:
   Actual number    Short scale name    Long scale name
   10^6      million         million
   10^9      billion         milliard
   10^12     trillion        billion
   10^15     quadrillion     billiard
   10^18     quintillion     trillion
   10^21     sextillion      trilliard

   And it goes on like that.

   Your task today is to write a program that will print out the name of a number
   in both long-scale and short-scale. So, for instance, given 1234567891111, it
   should print out

   Short scale: 1 trillion, 234 billion, 567 million, 891 thousand and 111
   Long scale:  1 billion, 234 milliard, 567 million, 891 thousand and 111

 */

void
printSSNString(size_t hm){
    static size_t i = hm;
    vector<string> ssn = {"thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion"};
    cout << ssn[i--] << " ";
}

void
printLSNString(size_t hm){
    static size_t i = hm;
    vector<string> lsn = {"thousand", "million", "milliard", "billion", "billiard", "trillion", "trilliard"};
    cout << lsn[i--] << " ";
}

void
printSSN(string num){
    size_t remaning = num.length()%3;
    size_t hm = num.length()/3-1;
    for (size_t j = 0; j < remaning; ++j) {
        cout << num[j] << " ";
    }
        printSSNString(hm);
    for (size_t i = remaning; i < num.length(); i = i+3) {
        string token = num.substr(i,3);
        cout << token << " ";
        printSSNString(hm);
    }
    cout << endl;
}

void
printLSN(string num){
    size_t remaning = num.length()%3;
    size_t hm = num.length()/3 -1;
    for (size_t j = 0; j < remaning; ++j) {
        cout << num[j] << " ";
    }
        printLSNString(hm);
    for (size_t i = remaning; i < num.length(); i = i+3) {
        string token = num.substr(i,3);
        cout << token << " ";
        printLSNString(hm);
    }
    cout << endl;
}

int
main(void){
    string num = "1234567891111";
    printSSN(num);
    printLSN(num);
}
