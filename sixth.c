#include <stdio.h>

int main() {
    int num, temp;
    int digit1, digit2, digit3, digit4, digit5;
    
    printf("Enter a five-digit number: ");
    scanf("%d", &num);
    
    if (num < -99999 || num > 99999 || (num > -10000 && num < 10000)) {
        printf("Invalid input! Please enter a five-digit number.\n");
        return 1;
    }
    
    int is_negative = (num < 0);
    if (is_negative) {
        num = -num;
    }
    
    temp = num;
    digit5 = (temp % 10 + 1) % 10;
    temp /= 10;
    digit4 = (temp % 10 + 1) % 10;
    temp /= 10;
    digit3 = (temp % 10 + 1) % 10;
    temp /= 10;
    digit2 = (temp % 10 + 1) % 10;
    temp /= 10;
    digit1 = (temp % 10 + 1) % 10;
    
    if (digit1 == 0 && digit2 == 0 && digit3 == 0 && digit4 == 0 && digit5 == 0) {
        printf("Modified number: 0\n");
    } else {
        printf("Modified number: %d%d%d%d%d\n", digit1, digit2, digit3, digit4, digit5);
    }
    
    return 0;
}
