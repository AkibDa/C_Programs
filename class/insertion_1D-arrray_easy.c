#include <stdio.h>

#define MAX_SIZE 100 // Define a maximum size for the array

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current number of elements in the array
    int elementToInsert, position;

    printf("Enter the number of elements (max %d): ", MAX_SIZE - 1); // -1 because we'll insert one
    scanf("%d", &size);

    if (size >= MAX_SIZE || size < 0) {
        printf("Invalid number of elements. Exceeds max size or is negative.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &elementToInsert);

    printf("Enter the position (0-indexed) to insert at: ");
    scanf("%d", &position);

    if (position < 0 || position > size) { // Position can be 'size' to append
        printf("Invalid position. Position must be between 0 and %d\n", size);
    } else if (size == MAX_SIZE) { // Check if array is already full
        printf("Array is full. Cannot insert more elements.\n");
    } else {
        // Shift elements to the right to make space
        for (int i = size - 1; i >= position; i--) {
            arr[i + 1] = arr[i];
        }

        // Insert the new element
        arr[position] = elementToInsert;
        size++; // Increment the current size of the array

        printf("Array after insertion: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}