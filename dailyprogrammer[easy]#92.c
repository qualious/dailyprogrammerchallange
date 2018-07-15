#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int to_int(char);
char* build_string_from_bits(const int*);
bool is_successive(const int*, int);
void flatten(char**);
void free_array(char**);

/*
 * 0 -> +---+
 * 1 -> |
 * 2 ->    |
 * 3 -> +---+
 * 4 -> |
 * 5 ->    |
 * 6 -> +---+
 * 7 -> +  
 * 8 ->     +
 * 9 -> +    +
*/

const int mapped_data[10][7] = {
    {0, 1, 2, 9, 4, 5, 6},  //0
    {8, 2, 8, 5, 8},        //1
    {0, 2, 3, 4, 6},        //2
    {0, 2, 3, 5, 6},        //3
    {9, 1, 2, 3, 5, 8},     //4
    {0, 1, 3, 5, 6},        //5
    {0, 1, 3, 4, 5, 6},     //6
    {0, 2, 8, 5, 8},        //7
    {0, 1, 2, 3, 4, 5, 6},  //8
    {0, 1, 2, 3, 5, 6}      //9
};

char* output[4] = {
    "+---+\n", 
    "|    \n|    \n", 
    "    |\n    |\n", 
    "|   |\n|   |\n",
};

const char* corners[3] = {
    "+    \n",
    "    +\n",
    "+   +\n"
};

int len;

int
main (int argc, char** argv) {
    if (argc == 1 || argc > 2) {
        puts("Usage: ./a <number>");
        return 1;
    }
    
    char* p;
    strtol(argv[1], &p, 10);
    if (*p != '\0') {
        puts("Bad input.");
        return 1;
    }

    char* num = argv[1];
    len = strlen(num);
    char* num_array[len];
    for (int i = 0; i < len; ++i) {
        const int* bits = mapped_data[to_int(num[i])];
        num_array[i] = build_string_from_bits(bits);
    }
    flatten(num_array);
    free_array(num_array);
    return 0;
}

int
to_int(char c) {
    return (int) c - '0';
}

char* 
build_string_from_bits(const int* arr) {
    char* num = calloc(100, sizeof(char));
    for (int j = 0; j < 7; ++j) {
        int bit = arr[j];
        if (j > 0 && bit == 0) break;
        else if (bit > 6) strcat(num, corners[bit - 7]);
        else if (is_successive(arr, j)) {
            ++j;
            strcat(num, output[3]);
        } else strcat(num, output[bit % 3]);
    }
    return num;
}

bool
is_successive(const int* arr, int index) {
    return (arr[index] % 3 == 1 && arr[index + 1] % 3 == 2);
}

void
flatten(char** nums) {
    for (int k = 0; k < 7; ++k) {
        for (int i = 0; i < len; ++i) {
            int _j = k * 5 + k;
            for (int j = _j; j < (_j + 5); ++j) {
                printf("%c", nums[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void 
free_array(char** nums) {
    for (int i = 0; i < len; ++i) {
        free(nums[i]);
    }
}