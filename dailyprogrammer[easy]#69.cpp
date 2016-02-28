#include <iostream>
#include <vector>
using namespace std;
/*
   Write a program that takes a title and a list as input and outputs the list in a
   nice column. Try to make it so the title is centered. For example:

   title: 'Necessities'
   input: ['fairy', 'cakes', 'happy', 'fish', 'disgustipated', 'melon-balls']

   output:

 +---------------+
 |  Necessities  |
 +---------------+
 | fairy         |
 | cakes         |
 | happy         |
 | fish          |
 | disgustipated |
 | melon-balls   |
 +---------------+

 */

int
main(void){
    string title = "Necessities";
    vector<string> v = {"fairy", "cakes", "happy", "fish", "disgustipated", "melon-balls"};
    printf("+---------------+\n|  %s  |\n+---------------+\n", title.c_str());
    for (size_t i = 0; i < v.size(); ++i) {
        if(v[i].length() >= title.length())
            cout << "| " << v[i] << "\t|\n";
        else
            cout << "| " << v[i] << "\t\t|\n";
    }
    cout << "+---------------+\n\n";
}
