#include <iostream>
#include <fstream>
using namespace std;
/*
Write a program that counts the number of alphanumeric characters
there are in The Adventures of Sherlock Holmes. Exclude the Project 
Gutenberg header and footer, book title, story titles, and chapters. 
Post your code and the alphanumeric character count.
*/

int
main(void){
    int count = 0, countignored = 0;
    ifstream file;
    file.open("sherlock.txt", ios::in);
    ifstream fileignored;
    fileignored.open("sherlockignored.txt", ios::in);
    string line;
    while (getline(file,line)){
      for(unsigned int i = 0; i < line.length(); ++i)
        if(isalnum(line[i]))
            count++;
    }
    while (getline(fileignored,line)){
      for(unsigned int i = 0; i < line.length(); ++i)
        if(isalnum(line[i]))
            countignored++;
    }
    file.close();
    fileignored.close();
    cout << (count - countignored) << endl;
}