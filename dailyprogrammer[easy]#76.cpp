#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
/*
   Write a function that transforms a string into title case. This mostly means:
   capitalizing only every first letter of every word in the string. However,
   there are some non-obvious exceptions to title case which can't easily be
   hard-coded. Your function must accept, as a second argument, a set or list
   of words that should not be capitalized. Furthermore, the first word of every
   title should always have a capital leter. For example:

   exceptions = ['jumps', 'the', 'over']
   titlecase('the quick brown fox jumps over the lazy dog', exceptions)

   This should return:
   The Quick Brown Fox jumps over the Lazy Dog

   An example from the Wikipedia page:
   exceptions = ['are', 'is', 'in', 'your', 'my']
   titlecase('THE vitamins ARE IN my fresh CALIFORNIA raisins', exceptions)

   Returns:
   The Vitamins are in my Fresh California Raisins
*/

int
main(void){
    stringstream s("the quick brown fox jumps over the lazy dog");
    vector<string> exceptions = {"jumps", "the", "over"};
    string token;
    while (getline(s, token, ' ')) {
        if(find(exceptions.begin(), exceptions.end(), token) != exceptions.end()){
            cout << token << " ";
            continue;
        }
        else{
            token[0] = toupper(token[0]);       //capatilize
            cout << token << " ";
        }
    }
}
