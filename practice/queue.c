#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

void Insert(int *queue, int *front, int *rear) {
  if (*rear == MAX_SIZE - 1 && *front == 0) {
    printf("Overflow! Cannot insert.\n");
  } else {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    if (*front == -1) {
      *front = 0; 
    }
    *rear = *rear + 1 ;
    queue[*rear] = value;
    printf("%d inserted into queue.\n", value);
  }
}

int Delete(int *queue, int *front, int *rear) {
  if (*front == -1) {
    printf("Underflow! Cannot delete.\n");
    return -1;
  } else {
    int deletedValue = queue[*front];
    if (*front == *rear) {
      *front = -1;
      *rear = -1;
    } else {
      *front = *front + 1;
    }
    return deletedValue;
  }
}

void Display(int *queue, int front, int rear) {
  if (front == -1) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main(){
  int *queue;
  int front = -1, rear = -1, choice;
  queue = (int *)malloc(MAX_SIZE * sizeof(int));
  if(queue == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  while (1) {
    printf("\n--- Queue Menu ---\n");
    printf("1. Insert (Add element)\n");
    printf("2. Delete (Remove element)\n");
    printf("3. Display queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        Insert(queue, &front, &rear);
        break;
      case 2:
        int deletedValue = Delete(queue, &front, &rear);
        printf("%d deleted from queue.\n", deletedValue);
        break;
      case 3:
        Display(queue, front, rear);
        break;
      case 4:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}