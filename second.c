#include <stdio.h>
int main() {
    
    int amount,one,five,hun,rest1,rest2;
    scanf("%d",&amount);
    
    if(amount%10!=0){
        printf("Invalid amount. Please enter a positive multiple of 10. ");
    }
    else if(amount < 0 || amount == 0) {
        printf("Invalid amount. Please enter a positive multiple of 10");
    }
    else {
        hun = amount / 100;
        rest1 = amount % 100;
        five = rest1 / 50;
        rest2 = rest1 % 50;
        one = rest2 / 10;
        printf("100s: %d\n",hun);
        printf("50s: %d\n",five);
        printf("10s: %d\n",one);
    }
    
    return 0;
}