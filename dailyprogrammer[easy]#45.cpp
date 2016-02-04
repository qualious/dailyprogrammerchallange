#include <iostream>
using namespace std;
/*
Your challenge today is to write a program that can draw a checkered grid
(like a chessboard) to any dimension. For instance, a 3 by 8 board might look like this:
*****************************
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*   *###*   *###*   *###*   *###*
*****************************
*/
int
main(void){
    size_t row = 5;
    size_t column = 8;
    for(unsigned int i = 0; i < row; ++i){
        for(unsigned int j = 0; j < column; ++j){
            if(j%2)
                cout << "██";
            else
                cout << " ";
        }
        cout << endl;
    }
}
