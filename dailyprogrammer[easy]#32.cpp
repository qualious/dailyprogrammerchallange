#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
a program that takes as input your bet, 
and gives as output how much you won, with the appropriate probability
write a program that will take a players bet and 
output the resulting spin and payout. try using an american roulette
wheel (which has the 00 slot) to add a slight twist. and try to incorporate 
as many complex bets as you can to. a comprehensive list can be found here
*/

int 
main(void){
    srand (time(NULL));
    int bet;
    cout << "Place your bets gentlemens!(00-36)" << endl;
    cin >> bet;
    if(rand()%36 == bet){
        cout << "You win!\n";
    }else
        cout << "Ah.. You lose, the rolled number was: " 
            << rand()%36 << endl;
}