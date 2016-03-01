#include <iostream>
#include <cmath>
using namespace std;
/*
   If a right angled triangle has three sides A, B and C (where C is the hypothenuse),
   the pythagorean theorem tells us that A2 + B2 = C2

   When A, B and C are all integers, we say that they are a pythagorean triple.
   For instance, (3, 4, 5) is a pythagorean triple because 3^2 + 4^2 = 5^2 .

   When A + B + C is equal to 240, there are four possible pythagorean triples:
   (15, 112, 113), (40, 96, 104), (48, 90, 102) and (60, 80, 100).

   Write a program that finds all pythagorean triples where A + B + C = 504.
 */
int
main(void){
    size_t num = 504;
    for (size_t i = 1; i < num; ++i) {
        for (size_t j = i; j < num; ++j) {
            if(pow(i,2) + pow(j,2) == pow((num-i-j),2))
                printf("%zu\t %zu\t  %zu \n", i, j, num-i-j);
        }
    }
}
