#include <iostream>
#include <cmath>
using namespace std;
/*
   Like many people who program, I got started doing this because I wanted to
   learn how to make video games.
   As a result, my first ever 'project' was also my first video game. It
   involved a simple text adventure I called "The adventure of the barren moor"

   In "The adventure of the barren moor" the player is in the middle of an
   infinite grey swamp. This grey swamp has few distinguishing characteristics,
   other than the fact that it is large and infinite and dreary. However, the
   player DOES have a magic compass that tells the player how far away the next
   feature of interest is.

   The player can go north,south,east,or west. In my original version of the game,
   there was only one feature of interest, a treasure chest at a random point in
   the world.

   Here is an example playthrough of my old program:

   You awaken to find yourself in a barren moor.  Try "look"
   > look
   Grey foggy clouds float oppressively close to you,
   reflected in the murky grey water which reaches up your shins.
   Some black plants barely poke out of the shallow water.
   Try "north","south","east",or "west"
   You notice a small watch-like device in your left hand.
   It has hands like a watch, but the hands don't seem to tell time.

   The dial reads '5m'

   >north
   The dial reads '4.472m'
   >north
   The dial reads '4.123m'
   >n
   The dial reads '4m'
   >n
   The dial reads '4.123m'
   >south
   The dial reads '4m'
   >e
   The dial reads '3m'
   >e
   The dial reads '2m'
   >e
   The dial reads '1m'
   >e

   You see a box sitting on the plain.   Its filled with treasure!  You win!
   The end.

   The dial reads '0m'

 */
typedef struct xyplane{
    ptrdiff_t x;
    ptrdiff_t y;
}XY;

void
printDistance(XY p, XY a){
    cout << "The dial reads " << sqrt( (pow(a.y,2)-pow(p.y,2)) + (pow(a.x,2)-pow(p.x,2)) ) << endl;
}
int
main(void){
    cout << "Story\n\n";
    string input;
    getline(cin,input);
    if(input != "look"){
        cout << "You should look around first!\n";
    }
    else{
        XY p,a;
        p.x = 0; a.x = 3;
        p.y = 0; a.y = 4;
        cout << "It has hands like a watch, but the hands don't seem to tell time. \n";
        printDistance(p,a);
        while(p.x != a.x && p.y != a.y){
            getline(cin,input);
            if(input == "north"){
                ++p.y;
                printDistance(p,a);
                continue;
            }
            if(input == "south"){
                --p.y;
                printDistance(p,a);
                continue;
            }
            if(input == "north"){
                ++p.x;
                printDistance(p,a);
                continue;
            }
            if(input == "north"){
                --p.x;
                printDistance(p,a);
                continue;
            }
        }
        cout << "You won! Congratz\n";
    }
}
