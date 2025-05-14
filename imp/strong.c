#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num, temp, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong number.\n", num);
    else
        printf("%d is not a Strong number.\n", num);

    return 0;
}
