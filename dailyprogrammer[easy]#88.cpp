#include <iostream>
#include <map>
using namespace std;
/*
The easy challenge today is to implement the famous Vigenère cipher.
The Wikipedia article explains well how it works, but here's a short
description anyway:

You take a message that you want to encrypt, for instance "THECAKEISALIE"
(lets assume that all characters are upper-case and there are no spaces in
the messages, for the sake of simplicity), and a key you want to encrypt it
with, for instance "GLADOS". You then write the message with the key
repeated over it, like this:

GLADOSGLADOSG
THECAKEISALIE

The key is repeated as often as is needed to cover the entire message.

Now, one by one, each letter of the key is "added" to the letter of the
clear-text to produce the cipher-text. That is, if A = 0, B = 1, C = 2,
etc, then E + G = K (because E = 4 and G = 6, and 4 + 6 = 10, and K = 10).
If the sum is larger than 25 (i.e. larger than Z), it starts from the beginning,
so S + K = C (i.e. 18 + 10 = 28, and 28 - 26 is equal to 2, which is C).

For a full chart of how characters combine to form new characters, see here

The cipher text then becomes:

GLADOSGLADOSG
THECAKEISALIE
-------------
ZSEFOCKTSDZAK

Write funtions to both encrypt and decrypt messages given the right key.
*/

string
encode(string secret, string key, map<char,size_t> alphabet){
    string encoded;
    for (size_t i = 0; i < secret.length(); ++i) {
        encoded += key[i%key.length()];
    }
    for (size_t i = 0; i < encoded.length(); ++i) {
        encoded[i] = ((encoded[i] + alphabet[secret[i]]) > 90 ? ((encoded[i] + alphabet[secret[i]])%90+64) : (encoded[i] + alphabet[secret[i]]));
    }
    cout << "ecoded : " << encoded << endl;
    return encoded;
}

void
decode(string encoded, string key, map<char,size_t> alphabet){
    for (size_t i = 0; i < encoded.length(); ++i) {
        encoded[i] = ((encoded[i] - key[i%key.length()])%26+65) < 65 ? ((encoded[i] - key[i%key.length()])%26+91): ((encoded[i] - key[i%key.length()])%26+65);
    }
    cout << "decoded: " << encoded << endl;
}

int
main(void){
    string secret = "THECAKEISALIE", key="GLADOS", encoded;
    map<char,size_t> alphabet = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20},{'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}};
    encoded = encode(secret,key,alphabet);
    decode(encoded, key, alphabet);
}
