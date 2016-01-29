#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
Write a program that prints a string from a list at random, expects input, 
checks for a right or wrong answer, and keeps doing it until the user types 
"exit". If given the right answer for the string printed, it will print another and 
continue on. If the answer is wrong, the correct answer is printed and the program continues.

*/

int
main(void){
    srand (time(NULL));
    string input;
    string answers[10] = {"Mr poopybutthole", "Hello World", "Carrot", \
                            "Fish memes", "Rise Against", "Spotify", "Yes", "No","Maybe","Perhaps"};
    string questions[10] = {"Fav char at Rick&Morty ? ", "Most used print string ?", "A orange vegetable ?"
                            "Most used me_irl meme ? ", "Fav band ? ", "Music source ? ", "Is this question true ? "
                                "Is this question false ? ", "Is there a heaven ? ", "Am i dying inside ?"};
    while(true){ 
        int rd = rand()%10;
        cout << questions[rd] << endl;
        cout << "Answer : ";
        getline(cin,input);
        if(input == "exit")
            break;
        while(input != answers[rd]){
            cout << "Wrong, please enter the answer again! Type exit if you want to quit." << endl;
            getline(cin,input);
            if(input == "exit")
               break;
        }
    }

}