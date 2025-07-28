#include <stdio.h>

#define MAX_SIZE 5 // Max for both rows and columns

// Function to print a 2D array
void print2DArray(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int originalArray[MAX_SIZE][MAX_SIZE];
    int transposedArray[MAX_SIZE][MAX_SIZE]; // Max size ensures space for transpose
    int rows, cols;

    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows < 1 || cols < 1) {
        printf("Invalid dimensions. Max dimensions are %dx%d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements for the 2D array:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &originalArray[i][j]);
        }
    }

    // Perform transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedArray[j][i] = originalArray[i][j];
        }
    }

    printf("Original 2D Array:\n");
    print2DArray(originalArray, rows, cols);

    printf("\nTransposed 2D Array:\n");
    // When printing transposed, swap rows and cols for the print function
    print2DArray(transposedArray, cols, rows);

    return 0;
}