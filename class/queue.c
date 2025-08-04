#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

// Structure for the queue
struct Queue {
  int items[MAX_SIZE];
  int front; // Index of the front of the queue
  int rear;  // Index of the rear of the queue
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
  q->front = -1;
  q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
  if ((q->front == 0 && q->rear == MAX_SIZE - 1) || (q->front == q->rear + 1)) {
    return 1; // It is full
  }
  return 0; // It is not full
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
  if (q->front == -1) {
    return 1; // It is empty
  }
  return 0; // It is not empty
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* q, int value) {
  if (isFull(q)) {
    printf("Queue is full! Cannot enqueue.\n");
  } else {
    if (q->front == -1) {
      q->front = 0; // Initialize front for the first element
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // Use modulo for circular array logic
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
  }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* q) {
  int dequeuedValue;
  if (isEmpty(q)) {
    printf("Queue is empty! Cannot dequeue.\n");
    return -1; // Return a sentinel value for error
  } else {
    dequeuedValue = q->items[q->front];
    if (q->front == q->rear) {
      initQueue(q); // Reset the queue if the last element is dequeued
    } else {
      q->front = (q->front + 1) % MAX_SIZE; // Use modulo for circular array logic
    }
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
  }
}

// Function to display the elements of the queue
void display(struct Queue* q) {
  int i;
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue elements: ");
    // Loop from front to rear, handling the circular nature
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
      printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]); // Print the last element at rear
  }
}

// Main function with a menu
int main() {
  struct Queue myQueue;
  initQueue(&myQueue);

  int choice;
  int value;

  while (1) {
    printf("\n--- Queue Menu ---\n");
    printf("1. Enqueue (Add element)\n");
    printf("2. Dequeue (Remove element)\n");
    printf("3. Display queue\n");
    printf("4. Check if empty\n");
    printf("5. Check if full\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        enqueue(&myQueue, value);
        break;
      case 2:
        dequeue(&myQueue);
        break;
      case 3:
        display(&myQueue);
        break;
      case 4:
        if (isEmpty(&myQueue)) {
            printf("Queue is empty.\n");
        } else {
            printf("Queue is not empty.\n");
        }
        break;
      case 5:
        if (isFull(&myQueue)) {
            printf("Queue is full.\n");
        } else {
            printf("Queue is not full.\n");
        }
        break;
      case 6:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}