#include <iostream>
#include <vector>
using namespace std;
/*
   Morse code, as we are all aware, consists of dots and dashes. Lets define a
   "Morse code sequence" as simply a series of dots and dashes (and nothing else).
   So ".--.-.--" would be a morse code sequence, for instance.

   Dashes obviously take longer to transmit, that's what makes them dashes.
   Lets say that a dot takes 1 unit of time to transmit, and a dash takes 2 units
   of time. Then we can say that the "size" of a certain morse code sequence is the
   sum of the time it takes to transmit the dots and dashes. So, for instance
   "..-." would have a size of 5 (since there's three dots taking three units of
   time and one dash taking two units of time, for a total of 5). The sequence
   "-.-" would also have a size of 5.

   In fact, if you list all the the possible Morse code sequences of size 5,
   you get:

   .....  ...-  ..-.  .-..  -...  .--  -.-  --.

   A total of 8 different sequences.

   Your task is to write a function called Morse(X) which generates all morse code
   sequences of size X and returns them as an array of strings (so Morse(5) should
   return the 8 strings I just mentioned, in some order).

   Use your function to generate and print out all sequences of size 10.
 */


vector<string> morseCombinations;

void
print(vector<string> v){
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

void
morse(int length,std::string result){
    if(!length){
         morseCombinations.push_back(result);
         return;
    }
    else if(length < 0)
        return;
    morse(length-1, result + '.');
    morse(length-2, result + '-');
}

int
main(void){
    morse(5,"");
    print(morseCombinations);
}
