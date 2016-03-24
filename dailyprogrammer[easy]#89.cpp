#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
For today's challenge, you should calculate some simple statistical values
based on a list of values. Given this data set, write functions that will calculate:

    The mean value
    The variance
    The standard deviation

Obviously, many programming languages and environments have standard
functions for these (this problem is one of the few that is really easy to solve
in Excel!), but you are not allowed to use those! The point of this problem is
to write the functions yourself.
*/
int
main(void){
    vector<double> nums = {1.2, 2.3, 3.1, 21.4, 11.3};
    double mean, variance, stdev, sum = 0, sumV = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    mean = sum/nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
        sumV += pow((mean - nums[i]),2);
    }
    variance = sumV/nums.size();
    stdev = sqrt(variance);
    cout << "mean: " << mean << "\nvariance: " << variance << "\nstandart deviation: " << stdev << endl;
}
