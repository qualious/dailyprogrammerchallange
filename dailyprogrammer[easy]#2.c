#include <stdio.h>
/*Hello, coders! An important part of programming is being able to apply your programs, 
so your challenge for today is to create a calculator application that has use in your life. 
It might be an interest calculator, or it might be something that you can use in the classroom. 
For example, if you were in physics class, you might want to make a F = M * A calc.
EXTRA CREDIT: make the calculator have multiple functions! Not only should it be able to calculate
F = M * A, but also A = F/M, and M = F/A!
*/

void
main(void){
    int input = getWhichFunction();
    double F = 0, M = 0, A = 0;
    switch(input){
        case 1:
            getInput(&F, &M, &A);
            F = A * M;
            printf("%.2f\n", F);
            break;
        case 2:
            getInput(&F, &M, &A);
            M = F / A;
            printf("%.2f\n", M);
            break;
        case 3:
            getInput(&F, &M, &A);
            A = F / M;
            printf("%.2f\n", A);
            break;
        case 4:
            printf("Alrite fam whatever floats your boat\n");
            break;
    }        
}   

inline int
getWhichFunction(void){
    int input;
    printf("Alrite fam, what do you want to calculate today ? \n"
        "\t1. Gimme dat force calculation fam      \n"
        "\t2. eyy give me dat mass calculation     \n"
        "\t3. Gib acceleration calculation pls     \n"
        "\t4. quit pls don't meant to open this, thank             \n");
    scanf("%d", &input);
    return input;
}

inline void
getInput(double* F, double* M, double* A){
    printf("Can you please give the Force (N) [ENTER '0' IF NONE GIVEN] ?\n");
    scanf("%lf", F);
    printf("Can you please give the Mass (kg) [ENTER '0' IF NONE GIVEN] ?\n");
    scanf("%lf", M);
    printf("Can you please give the Acceleration (m/s^2) [ENTER '0' IF NONE GIVEN] ?\n");
    scanf("%lf", A);
}