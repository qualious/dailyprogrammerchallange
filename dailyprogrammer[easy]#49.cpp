#include <iostream>
#include <cstdlib>
#include <ctime>
#define goat 0
#define car 1
#define open -1
using namespace std;
/*
The Monty Hall Problem is a probability brain teaser that has a rather unintuitive
solution.
The gist of it, taken from Wikipedia:
Suppose you're on a game show, and you're given the choice of three doors:
Behind one door is a car; behind the others, goats. You pick a door, say No. 1
[but the door is not opened], and the host, who knows what's behind the doors,
opens another door, say No. 3, which has a goat. He then says to you, "Do you
want to pick door No. 2?" Is it to your advantage to switch your choice?
(clarification: the host will always reveal a goat)
Your task is to write a function that will compare the strategies of switching
and not switching over many random position iterations. Your program should output
the proportion of successful choices by each strategy. Assume that if both
unpicked doors contain goats the host will open one of those doors at random
with equal probability.

If you want to, you can for simplicity's sake assume that the player picks the
first door every time. The only aspect of this scenario that needs to vary is
what is behind each door.
*/
int
main(void){
    srand(time(NULL));
    cout << "Not switched : ";
    size_t count = 0;
    for(unsigned int i = 0; i < 100; ++i){
        size_t door1 = rand()%2;                                  //car or goat
        size_t door2 = ((door1 == goat) ? rand()%2 : goat);      //if door1 is goat, random; else goat
        size_t door3 = ((door2 == goat) ? ((door1 == goat) ? car : goat) : goat);
        //first always picks door2
        if(door2 == car)
            count++;                                            //counting the ones that we won
    }
    cout << count << endl;
    cout << "Switched : ";
    count = 0;
    size_t notWonCount = 0;
    for(unsigned int i = 0; i < 100; ++i){
        size_t door1 = rand()%2;                                 //car or goat
        size_t door2 = ((door1 == goat) ? rand()%2 : goat);      //if door1 is goat, random; else goat
        size_t door3 = ((door2 == goat) ? ((door1 == goat) ? car : goat) : goat);
        //first always picks door2
        if(door2 == car){
             notWonCount++;                                           //counting the ones that we lost
        }else{
            //door1 or door3 is car
            //open the not car one
            if(door1 == car)
                door3 == open;
            else
                door1 == open;
            if(door1 != open && door1 == car)
                count++;
            else if(door3 != open && door3 == car)
                count++;
        }
    }
    cout << count - notWonCount << endl;
}
