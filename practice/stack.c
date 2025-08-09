#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void push(int *stack,int *top){

  int value;

  if (*top == MAX - 1) {
    printf("Stack Overflow! Cannot push %d.\n", value);
  } else {
    printf("Enter value to push: ");
    scanf("%d", &value);
    *top += 1;
    stack[*top] = value;
    printf("%d pushed to stack.\n", value);
  }

}

void pop(int *stack, int *top) {

  if (*top == -1) {
    printf("Stack Underflow! Cannot pop from empty stack.\n");
  } else {
    int popped_item = stack[*top];
    *top -= 1;
    printf("%d popped from stack.\n", popped_item);
  }

}

void peep(int *stack, int top) {

  if (top == -1) {
    printf("Stack is empty! No element to peep.\n");
  } else {
    printf("Top element is: %d\n", stack[top]);
  }

}

void display(int *stack, int top) {

  if (top == -1) {
    printf("Stack is empty. Nothing to display.\n");
  } else {
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
      printf("%d\n", stack[i]);
    }
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

  int choice;

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
        push(stack, &top);
        break;
      case 2:
        pop(stack, &top);
        break;
      case 3:
        peep(stack, top);
        break;
      case 4:
        display(stack, top);
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