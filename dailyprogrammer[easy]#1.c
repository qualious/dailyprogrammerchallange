#include <stdio.h>
/*
create a program that will ask the users 
name, age, and reddit username. have it tell them the information back, 
in the format:
your name is (blank), you are (blank) years old, and your username is (blank)
for extra credit, have the program log this information in a file 
to be accessed later.
*/
#define MAX_CHAR 15
void 
main(void){
    char* name = (char*) malloc(MAX_CHAR*sizeof(char));
    char* username = (char*) malloc(MAX_CHAR*sizeof(char));
    int age;
    printf("Name ?\n");
    fgets(name, 10, stdin);         // fgets() scans and stores the trailing \n
    strtok(name, "\n");             // this tokens out the \n char
    getchar();                      // clean buffer
    printf("Age ?\n");
    scanf("%d", &age);
    printf("Reddit username ?\n");
    getchar();                     
    fgets(username, 25, stdin);
    strtok(username, "\n");
    printf("Your name is %s, you are %d years old, and your username is %s\n",
         name, age, username);  
    free(name);                    //free the allocated memory
    free(username);
}