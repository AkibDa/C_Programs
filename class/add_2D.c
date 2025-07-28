#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Function to print a 2D array
void print2DArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int array1[MAX_ROWS][MAX_COLS];
    int array2[MAX_ROWS][MAX_COLS];
    int sumArray[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows for both arrays (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns for both arrays (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS || rows < 1 || cols < 1) {
        printf("Invalid dimensions. Max dimensions are %dx%d.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    printf("Enter %d elements for Array 1:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array1[i][j]);
        }
    }

    printf("Enter %d elements for Array 2:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array2[i][j]);
        }
    }

    // Add corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sumArray[i][j] = array1[i][j] + array2[i][j];
        }
    }

    printf("\nArray 1:\n");
    print2DArray(array1, rows, cols);

    printf("\nArray 2:\n");
    print2DArray(array2, rows, cols);

    printf("\nSum of the two arrays:\n");
    print2DArray(sumArray, rows, cols);

    return 0;
}