#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE]; 
int top = -1;        

int isEmpty() {
  return top == -1;
}

int isFull() {
  return top == MAX_SIZE - 1;
}

void push(int data) {
  if (isFull()) {
    printf("Stack Overflow! Cannot push %d.\n", data);
  } else {
    top++;
    stack[top] = data;
    printf("%d pushed to stack.\n", data);
  }
}

int pop() {
  if (isEmpty()) {
    printf("Stack Underflow! Cannot pop from empty stack.\n");
    return -1; 
  } else {
    int popped_item = stack[top];
    top--;
    printf("%d popped from stack.\n", popped_item);
    return popped_item;
  }
}

int peep() {
  if (isEmpty()) {
    printf("Stack is empty! No element to peep.\n");
    return -1; // Return a sentinel value indicating error
  } else {
      printf("Top element is: %d\n", stack[top]);
      return stack[top];
  }
}

void display() {
  if (isEmpty()) {
    printf("Stack is empty. Nothing to display.\n");
  } else {
      printf("Stack elements: ");
      for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
      }
      printf("\n");
  }
}

int main() {
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
        push(value);
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
