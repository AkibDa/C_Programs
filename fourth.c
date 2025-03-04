#include <stdio.h>
int main(){
    
    int number,f,l,s;
    scanf("%d",&number);
    
    
    if(number>=1000 && number<=9999 ){
        f = number / 1000;
        l = number % 10;
        s = f + l;
        printf("Sum of the first and last digit: %d",s);
        
    }
    else if(number<= -1000 || number<=-9999){
        f = number / 1000;
        l = number % 10;
        s = f + l;
        printf("Sum of the first and last digit: %d",s);
    }
    else {
        printf("Invalid Input! Please enter a four-digit number.");
    }
    
    return 0;
}