#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
/*
   Write a program that given a word will find all one-word anagrams for that word.
   So, for instance, if you put in "LEPROUS", it should return "PELORUS" and
   "SPORULE". As a dictionary, use this file, which is a 1.8 mb text-file with one
   word listed on each line, each word listed in lower-case. In this problem
   description, I've used upper-case for all words and their anagrams, but that is
   entirely optional, it's perfectly all right to use lower-case if you want to.

   Using your program, find all the one-word anagrams for "TRIANGLE".
*/
inline bool
isAnagram(string s1, string s2){
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
int
main(void){
    ifstream file;
    file.open("anagram.txt", ios::in);
    string line;
    string findAnagramsOf = "triangle";
    while (getline(file,line)) {
        if(isAnagram(line,findAnagramsOf))
            cout << line << endl;
    }
    file.close();
}
