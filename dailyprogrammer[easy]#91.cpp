#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;
/*
An anonymous user on world4ch's programming text board posted a thread in
early 2011 in which he describes an ingenious O(n) sorting algorithm.
This means it's, supposedly, more efficient than any sorting algorithm
ever invented. Some bloggers picked up on it, and dubbed the algorithm sleep sort:

#!/bin/bash
function f() {
    sleep "$1"
    echo "$1"
}
while [ -n "$1" ]
do
    f "$1" &
    shift
done
wait

This program takes some command line arguments, like ./sleepsort.sh 3 1 4 1 5 9,
and starts a new thread for each number in the list, which first sleeps for n
seconds, then prints n. After 1 second, both 1s are printed, then after 2
more seconds the 3 follows, etc. Because it only loops through the list of
numbers once, the algorithm appears to run in linear time.

Your task is to re-implement sleep sort in a language of your choice (which
might look trivial, but this challenge is all about learning how your
language handles multithreading.)
*/

int
main(int argc, char** argv){
    string s(argv[1]);
    vector<size_t> v;
    for (size_t i = 0; i < s.length(); ++i) {
        v.push_back(s[i] - '0');       //fetch argv
    }
    size_t largest = 0;

    for(unsigned int i = 0; i < v.size(); ++i){
        if (largest < v[i])
            largest = v[i];
        ptrdiff_t pid;
        // pid = fork();                //we should handle errors
        if ((pid = fork()) < 0)         //fork for creating child process
            cout << "Error. Child process can't initiated" << endl;
        if (pid == 0){
            sleep(v[i]);                //sleep for d[i]
            cout << v[i] << endl;
            return 0;                   //exit after child created
        }
    }
    sleep(largest);
}
