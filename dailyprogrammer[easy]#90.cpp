#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
/*
In this challenge, we propose a simple image file format for binary (2 color)
black-and-white images.
Rather than describing the image as a sequence of bits in a row, instead we
describe it in a little bit of a non-standard way.
Imagine a grid of white squares. On this grid, a single man carrying a large
black stamp stands on the square at 0,0. You can tell him 5 commands: walk
N,S,E,W, and stamP. This will cause him to wander around the grid, and when
he recieves a stamp command, he will change the white square there to black.
By giving him the sequence of commands of how to move, you can render an
arbitrary b+w image.
The input file will have two integers describing the size of the grid. Then,
it will contain a sequence of characters. These characters describe the
command sequence to execute to create the image. The program should output
the image in some way. For example, it might print it to a png file or print
it in ascii art to the screen.
As an example, the input file
5 5 PESPESPESPESPNNNNPWSPWSPWSPWSP
would output a 5x5 grid with an X in it.
*/
int
main(void){
    //5 5 PESPESPESPESPNNNNPWSPWSPWSPWSP
    ifstream file;
    file.open("input.txt",ios::in);
    if(!file){
       cout << "Can't open the file! Closing..." << endl;
       return -1;
    }
    for(string line; getline(file, line);){
        cout << line << endl;       //line
    }
    bool image[line[0]][line[2]] = {0};     //image[5][5]
    size_t j = 0, k = 0;
    //input starts from 4
    for(size_t i = 4; i < line.lenght(); ++i){
        if(line[i] == 'P')
            image[j][k] = !image[j][k];
        else if(line[i] == 'E'){ //east
            if(k == line[2]){
                cout << "Out of border! Breaking.."
                return EXIT_FAILURE;
            }
            image[j][++k];
        }
        else if(line[i] == 'W'){ //west
            if(!k){
                cout << "Out of border! Breaking.."
                return EXIT_FAILURE;
            }
            image[j][--k];
        }
        else if(line[i] == 'N'){ //north
            if(j == line[0]){
                cout << "Out of border! Breaking.."
                return EXIT_FAILURE;
            }
            image[++j][k];
        }
        else if(line[i] == 'S'){ //south
            if(!j){
                cout << "Out of border! Breaking.."
                return EXIT_FAILURE;
            }
            image[--j][k];
        }
        else
            continue;
    }
    return EXIT_SUCCESS;
}
