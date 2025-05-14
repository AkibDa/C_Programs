#include <stdio.h>

int main() {
    int num, temp, reversed = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;

    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    if (reversed == num)
        printf("%d is a Palindrome number.\n", num);
    else
        printf("%d is not a Palindrome number.\n", num);

    return 0;
}
