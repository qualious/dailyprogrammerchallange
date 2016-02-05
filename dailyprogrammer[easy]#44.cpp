#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Write a program that divides up some input text into sentences and then determines 
which sentence in the input has the most words. Print out the sentence with the most
words and the number of words that are in it. Optionally, also print out all words in 
that sentence that are longer than 4 characters.
Sentences can end in periods, exclamation points and question marks, but not colons or semi-colons.
*/

/*
If you need something to input, try Shylock's famous speech from Shakespeare's The Merchant of Venic
*/

size_t
findMax(size_t n){
    static size_t max = 0;
    if(n > max)
        max = n;
    return max;
}

int
main(void){
    string str;
    vector<string>token;
    cout << "Enter an input text to determine which sentence has the most words.\n";
    getline(cin,str);
    size_t found = str.find_first_of("?!.");
    size_t prevFound = 0;
    unsigned int i = 0;
    while (found != string::npos) {
        token.push_back(str.substr(prevFound+2,found-prevFound)); 
        prevFound = found;
        size_t MAX = findMax(token[i].length());
        found = str.find_first_of("?!.", found+1);
        ++i;
        if(found == string::npos){                           //If the input we looped ended.
            for(unsigned int j = 0; j < token.size(); ++j){  //Find the max worded string in the vec.
                if(token[j].length() == MAX){
                    cout << "\nMaximum word count is in this sentence :\n";
                    cout << token[j] << endl << endl;
                }
            }
            cout << "With " << MAX << " words";              //print char count of max string
        }
    }
    return 0;
}