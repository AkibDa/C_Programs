#include <stdio.h>
int main(){
    
    int num,temp;
    int d1,d2,d3,d4,d5;
    
    printf("Enter a five-digit number: ");
    scanf("%d",&num);
    
    int is_negative = (num<0);
    if (is_negative) {
        num = -num;
    }
    if(num<-99999 || num>99999 || (num>-10000 && num<10000)) {
        printf("Invalid input! Please enter a five-digit number.\n");
        return 1;
    }
     
    temp = num;
    d5 = (temp % 10 + 1) % 10;
    temp /= 10;
    d4 = (temp % 10 + 1) % 10;
    temp /= 10;
    d3 = (temp % 10 + 1) % 10;
    temp /= 10;
    d2 = (temp % 10 + 1) % 10;
    temp /= 10;
    d1 = (temp % 10 + 1) % 10;
    
    
    if(d1==0 && d2==0 && d3==0 && d4==0 && d5==0){
        printf("New number after incrementing each digit: 0\n");
    }
    else {
        printf("New number after incrementing each digit: %d%d%d%d%d\n",d1,d2,d3,d4,d5);
    }
    
    return 0;
    
}