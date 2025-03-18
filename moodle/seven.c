#include <stdio.h>
int main(){
    
    float b,d,h,g;
    
    printf("Enter the basic salary: ");
    scanf("%f",&b);
    
    if(b<0){
        printf("Invalid input! Salary cannot be negative. \n");
    }
    else {
        d = b * 0.40;
        h = b * 0.20;
        g = b + d + h;
        printf("Gross salary: %.2f",g);
    }
    
    return 0;
}