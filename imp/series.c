#include<stdio.h>

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    double sum = 0.0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        sum += 1.0 / factorial(i);
    }

    printf("Sum of the series: %.6f\n", sum);
    return 0;
}
// This program calculates the sum of the series 1/0! + 1/1! + 1/2! + ... + 1/n!