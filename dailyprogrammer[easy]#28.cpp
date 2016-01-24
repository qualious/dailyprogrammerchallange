#include <iostream>
#include <vector>
#include <chrono>           //time count
using namespace std;
using namespace std::chrono;
/*
The array duplicates problem is when one integer is in an array for more than once.
If you are given an array with integers between 1 and 1,000,000 or in some other 
interval and one integer is in the array twice. How can you determine which one?
Your task is to write code to solve the challenge.*/

void
efficentSearch(vector<int> v){
    vector<int> dublicateVector;
    for(unsigned int i = 0; i < 1000000; ++i){
        if(dublicateVector[i] == v[i]){
            cout << "Dublicate found! " << dublicateVector[i] << 
                " appers in the array two times! Quiting.. " << endl; 
            break;
        }
        dublicateVector.push_back(i);
    }
}

int 
main(void){
    vector<int> givenArray;
    for(int i = 0; i < 1000000; ++ i){
        givenArray.push_back(i);
        if(i == 20)
            givenArray.push_back(i);        //dublicate 20
    }
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    efficentSearch(givenArray);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Time it took to run the program: " << duration << " microseconds" << endl;
}