#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(){

  int *stack;
  int top = -1;
  int size;

  printf("Enter the size of the stack (max %d): ", MAX);
  scanf("%d", &size);
  if(size <= 0 || size > MAX) {
      printf("Invalid size! Please enter a size between 1 and %d.\n", MAX);
      return 1;
  }

  stack = (int *)malloc((MAX) * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

  return 0;

}