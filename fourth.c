#include <stdio.h>
int main(){
    
    int number,f,l,s;
    scanf("%d",&number);
    
    if(number<1000 || number>9999){
        printf("Invalid Input! Please enter a four-digit number.");
    }
    else {
        f = number / 1000;
        l = number % 10;
        s = f + l;
        printf("First digit: %d\n",f);
        printf("Last digit: %d\n",l);
        printf("Sum of first and last digits: %d",s);
    }
    
    return 0;
}