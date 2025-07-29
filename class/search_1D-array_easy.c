#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int elementToSearch;

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

    printf("Enter the element to search: ");
    scanf("%d", &elementToSearch);

    for (int i = 0; i < size; i++) {
        if (arr[i] == elementToSearch) {
            printf("Element %d found at index %d\n", elementToSearch, i);
            return 0; // Element found, no need to continue searching
        }
    }

    printf("Element %d not found in the array.\n", elementToSearch);

    return 0;
}