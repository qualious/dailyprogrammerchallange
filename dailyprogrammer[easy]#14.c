#include <stdio.h>
/*
Input: list of elements and a block size k or some other variable of your choice
Output: return the list of elements with every block of k elements reversed, 
starting from the beginning of the list.
For instance, given the list 12, 24, 32, 44, 55, 66 and the block size 2, 
the result is 24, 12, 44, 32, 66, 55.
*/
void 
printArray(int *a, int len){
  for(int i = 0; i < len; i++)
    printf("%d ", a[i]);
  putchar('\n');
}

void 
reverseBlock(int *a, int len, int b){
  for(int i = 0; i < len; i+=b) {
    int j, k;
    for (j = i,k = j+b-1; j < k && k < len; j++, k--) {
      int temp = a[j];
      a[j] = a[k];
      a[k] = temp;
    }
  }
  printArray(a, len);
}

int 
main(void){
    int num[10];
    printf("Enter an array\n");
    for(unsigned int i = 0; i < 10; ++i)
      scanf("%d", &num[i]);
    int b;
    printf("Enter a block size\n");
    scanf("%d", &b);
    reverseBlock(num, 10, b);
    return 0;
}