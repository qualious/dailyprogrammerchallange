#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
   A transposition cipher we'll call the "matrix cipher" can be defined as follows:
   write each character in the text that you want to encrypt in a matrix of some
   specified width, where the width is the key of the cipher. So, for instance, if
   you wanted to encrypt "The cake is a lie!" with the key 3, you would write it
   like so (the spaces are replaced with underscores for clarity):

   T h e
   _ c a
   k e _
   i s _
   a _ l
   i e !

   Then to get the ciphertext, you simply read off the columns one by one. So in
   this case, the ciphertext would be "T_kiaihces_eea__l!", or "T kiaihces eea
   l!" if you put the spaces back in.

   If the text doesn't fit the matrix perfectly, you add in random letters to
   fill in the last row. So, if we wanted to encode "The cake is a lie!" with key
   7, we'd construct this matrix:

   T h e _ c a k
   e _ i s _ a _
   l i e ! v m z

   Here "v", "m" and "z" have been added in to fill the last row, and the
   ciphertext is "Telh ieie s!c vaamk z".
   Write an implementation of the matrix cipher that can both encode and decode
   text given the correct key.
 */

string
encode(vector<string> v){
    string encrypted;
    size_t prevSize = v[0].size();
    for (size_t i = 0; i < v[0].size(); ++i) {
        for (size_t j = 0; j < v.size(); ++j) {
            if (v[j].size() != prevSize) {
                for (size_t k = 0; k < (prevSize - v[j].size()); ++k) {
                    v[j].push_back(static_cast<char>(rand()%26+97));    //push random char to string.
                }
            }
            prevSize = v[i].size();
            encrypted += v[j][i];
        }
    }
    replace (encrypted.begin(), encrypted.end(), '_' , ' ');
    return encrypted;
}

void
decode(vector<string>v, string encrypted){
    size_t len = v.size();  //6
    for (size_t j = 0; j < encrypted.length()/v[0].size(); ++j) {
        size_t i = j;
        for (; i < encrypted.length(); i = i + len) {
            cout << encrypted[i];
        }
    }
}

int
main(void){
    srand((unsigned)time(0));
    const char* args[] =  {"The", "_ca", "ke_", "is_", "a_l", "ie!"};
    vector<string> v(args,args+6);
    string encrypted = encode(v);
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: ";
    decode(v,encrypted);
}
