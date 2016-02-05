#include <iostream>
#include <bitset>
using namespace std;
/* 
The population count of a bitstring is the number of set bits (1-bits) 
in the string. For instance, the population count of the number 23, 
which is represented in binary as 10111 is 4.
*/
int 
main(void){
    int n;
    cout << "Enter a num to find the population cout : ";
    cin >> n;
    string binary = bitset<8>(n).to_string(); //to binary
    int total = 0;
    for(unsigned int i = 0; i < binary.length(); ++i){
        total += (binary[i] - '0');
    }
    cout << total;
}