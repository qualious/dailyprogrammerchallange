#include <iostream>
#include <vector>
using namespace std;
/*
In an election, the person with the majority of the votes is the winner. 
Sometimes due to similar number of votes, there are no winners.
Your challenge is to write a program that determines the winner of
a vote, or shows that there are no winners due to a lack of majority.
*/
int
main(void){
    vector<int> votes;
    int candits, vote;
    cout << "How many candidates ?" << endl;
    cin >> candits;
    for(unsigned int i = 1; i <= candits; ++i){
        cout << "How many votes did the " << i << ". candidate gathered ? " << endl;
        cin >> vote;
        votes.push_back(vote);
    }
    int max = -1;
    for(unsigned int i = 0; i < candits; ++i){
        if(votes[i] == max){
            cout << "No winners!" << endl;
            return 0;
        }
        if(votes[i] > max)
            max = votes[i];
    }
    for(unsigned int i = 0; i < candits; ++i){
        if(votes[i] == max){
            cout << i+1 << ". candidate won by " << max << " votes!" << endl;
        }
    }
}