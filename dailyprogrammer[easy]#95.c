#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Write a program that reads text from a file, and then 
outputs the text to another file but with all the lines 
reversed and all the words in each line reversed.

So, for instance, if you had one file called the 
"thetyger.txt" which contained the two first verses 
of William Blake's The Tyger:

Tyger! Tyger! burning bright 
In the forests of the night, 
What immortal hand or eye 
Could frame thy fearful symmetry? 

In what distant deeps or skies 
Burnt the fire of thine eyes? 
On what wings dare he aspire? 
What the hand dare sieze the fire? 

Your program would output this:

fire? the sieze dare hand the What
aspire? he dare wings what On
eyes? thine of fire the Burnt
skies or deeps distant what In

symmetry? fearful thy frame Could
eye or hand immortal What
night, the of forests the In
bright burning Tyger! Tyger!
*/

int
main(void) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;

    fp = fopen("tyger.txt", "r");
    while (getline(&line, &len, fp) != -1) {
        char* token = strtok(line, " ");
        while (token) {
	    	printf("%s\n", token);
		    token = strtok(NULL, " ");
		}
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}