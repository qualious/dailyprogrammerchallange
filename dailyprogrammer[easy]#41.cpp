#include <iostream>
using namespace std;
/*
Write a program that will accept a sentence as input and then output that
sentence surrounded by some type of an ASCII decoratoin banner.
*/
int
main(int argc, char** argv){
    string input(argv[1]);
    size_t len = input.length()/4;
    cout << "★　　★ ° ☾ ☆ ¸. ¸ 　★　 :.　 . • ○ ° ★　 .　 *　.　.　　¸ .　　 ° 　¸. * ● ¸ .　..." << input.substr(0, len) <<
     " ☾ ° 　¸. ● ¸ .　　★　° :.　 . • ° 　 .　 *　:.　. "<<input.substr(len, len*2) << 
     "* ● ¸ 　　　　° ☾ °☆ 　. * ¸.　　　★　★ ° . .　　　　.　☾ °☆ 　. * ● ¸ .." 
     "...° ☾　★ °● ¸ .　　　★　° :.　 . • ○ ° ★　 .　 * "<< input.substr(len*3, len*4) << " ☾　★ °● ¸ .　　　★　°\n";
}
