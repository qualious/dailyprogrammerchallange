#include <iostream>
#include <string>
using namespace std;
/*
Write a program that prints out the lyrics for "Ninety-nine bottles of beer", 
"Old McDonald had a farm" or "12 days of Christmas".
If you choose "Ninety-nine bottles of beer", you need to spell out the number, 
not just write the digits down. It's "Ninety-nine bottles of beer on the wall", not "99 bottles of beer"!
*/

string toWords(int num) {
    if (num > 100 || num < 1) {
        throw "unsupported";
    }
    if (num == 100) {
        return "one hundred";
    }
    const string kSpecialCases[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    if (10 <= num && num <= 19) {
      return kSpecialCases[num - 10];
    }
    const string kOnesPlaces[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const string kTensPlaces[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    if (num < 10) {
      return kOnesPlaces[num - 1];
    } else if (num % 10 == 0) {
      return kTensPlaces[num / 10 - 2];
    } else {
      return kTensPlaces[num / 10 - 2] + " " + kOnesPlaces[num % 10 - 1];
    }
}

int
main(void){
    size_t i = 99;  string bottle = " bottles of beer"; string take = "Take one down and pass it around, "; 
    string wall = " on the wall";
    while(true){
        if (i==1){
           cout << toWords(i) <<  bottle << wall << "," << toWords(i) << bottle << "." << endl
            << take << "no more" << bottle << wall << "." << endl << endl;
            break; 
        }
        cout << toWords(i) <<  bottle << wall << "," << toWords(i) << bottle << "." << endl
            << take << toWords(i-1) << bottle << wall << "." << endl << endl;

        --i;
    }
}