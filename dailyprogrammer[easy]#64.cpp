#include <iostream>
using namespace std;
/*
   The divisors of a number are those numbers that divide it evenly; for example,
   the divisors of 60 are 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, and 60. The sum of
   the divisors of 60 is 168, and the number of divisors of 60 is 12.

   The totatives of a number are those numbers less than the given number and coprime
   to it; two numbers are coprime if they have no common factors other than 1. The
   number of totatives of a given number is called its totient. For example, the
   totatives of 30 are 1, 7, 11, 13, 17, 19, 23, and 29, and the totient of 30 is 8.

   Your task is to write a small library of five functions that compute the divisors
   of a number, the sum and number of its divisors, the totatives of a number, and
   its totient.
 */

void
divisors(size_t n){
    //The divisors of a number are those numbers that divide it evenly
    for (size_t i = 1; i <= n; ++i) {
        if((n % i) == 0){
            cout << i << ", ";
        }
    }
    cout << "\b\b" << ".\n";
    cout << endl;
}

void
countofDivisors(size_t n){
    size_t count = 0;
    for (size_t i = 1; i <= n; ++i) {
        if(!(n % i)){
            ++count;
        }
    }
    cout << count << endl << endl;
}

void
sumofDivisors(size_t n){
    size_t sum = 0;
    for (size_t i = 1; i <= n; ++i) {
        if(!(n % i)){
            sum += i;
        }
    }
    cout << sum << endl << endl;
}

bool
isCoprime(size_t n, size_t i){
    for (size_t j = 2; j < n; ++j) {
        if(!(n%j) && !(i%j))        //if there is a int that can divide them both, false
            return false;
    }
    return true;
}

void
totaives(size_t n){
    //For example, the totatives of 30 are 1, 7, 11, 13, 17, 19, 23, and 29,
    for (size_t i = 0; i < n; ++i) {
        if(isCoprime(n,i))
            cout << i << ", ";
    }
    cout << "\b\b" << ".\n";
    cout << endl;
}

void
totient(size_t n){
    //and the totient of 30 is 8.
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if(isCoprime(n,i))
            ++count;
    }
    cout << count << endl;
}

int
main(void){
    size_t n = 30;
    cout << "Divisors of " << n << ": ";
    divisors(n);
    cout << "The count of the divisors of " << n << ": ";
    countofDivisors(n);
    cout << "Sum of divisors of " << n << ": ";
    sumofDivisors(n);
    cout << "Totaives of " << n << ": ";
    totaives(n);
    cout << "Totient of " << n << ": ";
    totient(n);
}
