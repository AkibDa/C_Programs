#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void push(int value,int *stack,int top){

  if (top == MAX - 1) {
    printf("Stack Overflow! Cannot push %d.\n", value);
  } else {
    ++top;
    stack[top] = value;
    printf("%d pushed to stack.\n", value);
  }
  
}


int main(){

  int *stack;
  int top = -1;

  stack = (int *)malloc((MAX) * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

  int choice, value;

  printf("Stack Implementation using Array\n");
  printf("--------------------------------\n");

  while (1) {

    printf("\n1. Push\n");
    printf("2. Pop\n");
    printf("3. Peep\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

      case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value, stack, top);
        break;
      case 2:
        pop();
        break;
      case 3:
        peep();
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting program.\n");
        exit(0); 
      default:
        printf("Invalid choice! Please try again.\n");

    }
  }

  return 0;

}