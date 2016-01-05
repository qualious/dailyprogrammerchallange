#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ALLOWED_INPUT 1000
/*
Write a program that can translate Morse code in the format of ...---...
A space and a slash will be placed between words. ..- / --.-
For bonus, add the capability of going from a string to Morse code.
Super-bonus if your program can flash or beep the Morse.
This is your Morse to translate:
.... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--
*/
char
getChar(char* str){
    int i;
    char* morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                             "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.-"};
    for(i = 0; i<26 ; ++i){
        if(!strcmp(str,morseCode[i]))
            return i;
    }
    return -33;
}

int
main(void){
    char input[MAX_ALLOWED_INPUT];                                          //create input buffer
    fgets(input,MAX_ALLOWED_INPUT,stdin);                                   //get input to buffer
    int inputLen = strlen(input);                                           //get input length
    char subInput[inputLen];                                                //create a subInput to token it afterwards
    strcpy(subInput,input);                                                 //copy input to sub input
    char *tokenWord = strtok(subInput, "/");                                //token the subInput
    int tokenWordLen = strlen(tokenWord);                                   //get the token's length in order to make substrings
    while(strcmp(input," ")){
        while (tokenWord != NULL) {
                //here your tokenWord is a word
                char *tokenLetter = strtok(input, " ");
                while(tokenLetter != NULL){
                    //here your tokenLetter is a letter(.... = H)
                    int ch = getChar(tokenLetter);                           //get the char a = 0, b = 1 and so on..
                    ch = ch + 65;                                            //add 65 in order to get ascii value of char
                    printf("%c", (char)ch);                                  //convert int to char and print it
                    tokenLetter = strtok(NULL, " ");
                }
            tokenWord = strtok(NULL, " / ");
        }
    memcpy(input, &subInput[tokenWordLen], (inputLen - tokenWordLen));       //copy the string after the token key (/) to the
    }                                                                        //actual input. Break from while loop after reaching to
}                                                                            //the end of the actual input. This achieved by calculating the
                                                                             //place of the token in the actual input(tokenWordLen)
                                                                            // and calculating the remaining input(inputLen - tokenWordLen).
