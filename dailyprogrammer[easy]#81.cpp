#include <iostream>
#include <vector>
using namespace std;
/*
   For a lot of the questions today we are going to be doing some simple numerical
   calculus. Don't worry, its not too terrifying.

   For the easy problem, write a function that can take in a list of y-values that
   represents a function sampled on some domain. The domain can be specified as a
   list of x-values or two values for the x-minimum and x-maximum (the x-coordinates
   of the endpoints)

   This function should output another list of values that represents the derivative
   of that function over the same domain.

   Python example:

   print derivative(xmin=-1,xmax=1,y=[-1.0,-.5,0,.5,1.0])

   outputs:

   [1.0,1.0,1.0,1.0,1.0]

 */
int
main(void){
    float xmin = -1, xmax = 1;
    vector<float>y = {-1.0,-.5,0,.5,1.0};
    for (size_t i = 1; i <= y.size(); ++i) {
        cout << (y[y.size()-i] - y[y.size()-i-1]) * (xmax-xmin) << " ";
    }
}
