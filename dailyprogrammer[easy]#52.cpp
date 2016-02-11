#include <iostream>
using namespace std;
/*
   Imagine each letter and its position within the alphabet. Now assign each
   letter its corresponding value ie a=1, b=2,... z=26. When given a list of
   words, order the words by the sum of the values of the letters in their names.
   Example: Shoe and Hat
   Hat: 8+1+20 = 29
   Shoe: 19+8+15+5 = 47
   So the order would be Hat, Shoe.
   For extra points, divide by the sum by the number of letters in that word
   and then rank them.
 */

int
calculateSum(string s){
    size_t alp[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
        25,26};
    size_t total = 0;
    for(int x: s){
        total += alp[(x-65)];
    }
    return total;
}

int
main(void){
    string s1("HAT");
    string s2("SHOE");
    size_t total1 = calculateSum(s1);
    size_t total2 = calculateSum(s2);
    size_t rank1 = total1 / s1.length();
    size_t rank2 = total2 / s2.length();
    if(rank1 > rank2)
        cout << s1 << ", " << s2 << endl;
    if(rank2 > rank1)
        cout << s2 << ", " << s1 << endl;
}
