#include <iostream>
#include <vector>
#include <chrono>           //function time count
using namespace std;
using namespace std::chrono;    //high_resolution_clock::time_point;
/*
The array duplicates problem is when one integer is in an array for more than once.
If you are given an array with integers between 1 and 1,000,000 or in some other 
interval and one integer is in the array twice. How can you determine which one?
Your task is to write code to solve the challenge.
*/
void
inefficentSearch(vector<int> v){
    int flag = -1;
    for(unsigned int i = 1; i < v.size()-1; ++i){
        for(unsigned int j = i+1; j < v.size(); ++j){
            if(v[j] == v[i]){
                cout << "Dublicate found! " << v[i] << 
                    " appers in the array two times! Quiting.. " << endl;
                return; 
            }
        }
    }
}

void
efficentSearch(vector<int> v){
    bool bv[v.size()] = {false};                            //initilize a bool vector
    for(unsigned int i = 0; i < v.size(); ++i){
        if(bv[v[i]]){                                       //if value set to true earlier
            cout << "Dublicate found! " << v[i] <<          //we found our duplicate
                " appers in the array two times! Quiting.. " << endl;
            return;
        }
        bv[v[i]] = true;                                    //make present values true
    }
}

int 
main(void){
    vector<int> givenArray;
    for(unsigned int i = 0; i < 1000000; ++ i){
        givenArray.push_back(i);
    }
    givenArray.push_back(98);    //duplicate 98 in last index. This is worst case scenario.

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout << "initializing inefficentSearch.." << endl;
    inefficentSearch(givenArray);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Time it took to run the program: " << duration << " microseconds" << endl << endl;


    cout << "initializing efficentSearch.." << endl;
    t1 = high_resolution_clock::now();
    efficentSearch(givenArray);
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Time it took to run the program: " << duration << " microseconds" << endl;
}