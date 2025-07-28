#include <stdio.h>

#define MAX_SIZE 100 // Define a maximum size for the array

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current number of elements in the array
    int elementToDelete;
    int indexToDelete = -1;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to delete: ");
    scanf("%d", &elementToDelete);

    // Find the index of the element to delete
    for (int i = 0; i < size; i++) {
        if (arr[i] == elementToDelete) {
            indexToDelete = i;
            break; // Found the first occurrence, stop searching
        }
    }

    if (indexToDelete == -1) {
        printf("Element %d not found in the array.\n", elementToDelete);
    } else {
        // Shift elements to the left to "delete" the element
        for (int i = indexToDelete; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; // Decrement the current size of the array

        printf("Array after deletion: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}