#include <iostream>
#include <vector>
using namespace std;
/*
   You receive a credit C at a local store and would like to buy two items.
   You first walk through the store and create a list L of all available items.
   From this list you would like to buy two items that add up to the entire
   value of the credit. The solution you provide will consist of the two integers
   indicating the positions of the items in your list (smaller number first).

   For instance, with C=100 and L={5,75,25} the solution is 2,3; with
   C=200 and L={150,24,79,50,88,345,3} the solution is 1,4; and with C=8 and
   L={2,1,9,4,4,56,90,3} the solution is 4,5.
 */
int
main(void){
        size_t C = 200;
        vector<size_t> v = {150,24,79,50,88,345,3};   //1,4
        for (size_t i = 0; i < v.size(); ++i) {
                if(v[i] > C) {
                        continue;
                }else{
                        for (size_t j = 0; j < v.size(); ++j) {
                                if(v[j] + v[i] == C)
                                        cout << j+1 << ", " << i << endl;
                                        break;
                        }
                }
        }
}
