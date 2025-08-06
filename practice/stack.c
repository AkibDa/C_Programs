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