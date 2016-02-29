#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*
   Write a program that takes a filename and a parameter n and prints the n most
   common words in the file, and the count of their occurrences, in descending order.
 */
//WHERE IS THE PYTHON DIRECTIONARIES WHEN YOU NEED THEM
int
main(int argc, char** argv){
    ifstream file;
    file.open(argv[1],ios::in);
    if(!file){
        cout << "Can't open the file! Closing..." << endl;
        return -1;
    }

    vector<string> v;
    for(string line; getline(file, line);){
        v.push_back(line);
    }

    sort(v.begin(),v.end());

    vector<size_t> count; size_t prevI = 0;
    for(size_t i = 0; i < v.size(); ++i){
        if(v[i] == v[i-1] && v[i] != v[i+1]){
            count.push_back(i+1-prevI);
            prevI = i+1;
            }
    }
    size_t prevCount = 0;
    for (size_t i = 0; i < count.size(); ++i) {
        cout << v[prevCount + count[i]-1] << "\t -> " << count[i] << endl;
        prevCount += count[i];
    }
}
