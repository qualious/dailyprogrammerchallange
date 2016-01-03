#include <iostream>
#include <fstream>
using namespace std;
/*
You challange for today is to creat a program which is password protected,
and wont open unless the correct user and password is given.
For extra credit, have the user and password in a seperate .txt file.
For even more credit, break into your own program
*/
int
main(int argc, char *argv[]){
    ifstream file;                              //for extra you have to use one more file, can't
    file.open("password.txt", ios::in);         //seem to make challange harder. Skipping extra.
    if(!file){
        cout << "Can't open the file! Closing..." << endl;
        return 1;
    }
    // char pass[10]="password";
    // file.write(pass,10);
    string password;
    file >> password;
    if(argv[1] == password)
        cout << "Password accepted" << endl;
    else
        cout << "Password denied" << endl;
    file.close();
    return 0;
}