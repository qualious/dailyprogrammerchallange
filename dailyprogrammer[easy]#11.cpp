#include <iostream>
#include <stdlib.h>
using namespace std;
/*
The program should take three arguments. The first will be a day, 
the second will be month, and the third will be year. Then, your 
program should compute the day of the week that date will fall on.
*/
string
days(int dayOfWeek){
    size_t days[8] = {" ", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
    return days[dayOfWeek];
}

int 
anchorDay(int yearPrefix){
    switch(yearPrefix){
        case 14:
        case 18:
        case 22:
        case 26:
            return 5;           //Friday
        case 15:
        case 19:
        case 23:
        case 27:
            return 3;           //Wednesday
        case 16:
        case 20:
        case 24:
        case 28:
            return 2;           //Tuesday
        case 17:
        case 21:
        case 25:
        case 29:
            return 7;           //Sunday
    }
}
int 
doomsDay(int month, char* year){
    switch(month){
        case 1:
            if(atoi(year) % 4 == 0)
                return 4;
            else
                return 3;
        case 2:
            if(atoi(year) % 4 == 0)
                return 29;
            else
                return 28;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 9;
        case 6:
            return 6;
        case 7:
            return 11;
        case 8:
            return 8;
        case 9:
            return 5;
        case 10:
            return 10;
        case 11:
            return 7;
        case 12:
            return 12;
    }
}

int
main(int argc,char ** argv){
    int lastTwoDigits = ((argv[3][2] - '0')*10 + argv[3][3] - '0');
    int leftOver = lastTwoDigits % 12;     
    int result = lastTwoDigits / 12;       
    int howMany4 = leftOver / 4;
    int _remainder = (leftOver + result + howMany4) % 7;
    int _anchorDay = anchorDay((argv[3][0] - '0')*10 + argv[3][1] - '0');
    int dayInt = (_anchorDay + _remainder) % 7;
    string doomsDayofMonth = days(dayInt);
    int month = ((argv[2][0] - '0')*10 + argv[2][1] - '0');
    int doomsDayDate = doomsDay(month, argv[3]);
    doomsDayofMonth = days((abs(atoi(argv[1]) - doomsDayDate) + dayInt) % 7);
    cout << doomsDayofMonth << endl;
}
