#include <stdio.h>
int main(){
    int d;
    float f;
    scanf("%d",&d);
    
    if (d>=1 && d<=5){
        f = 0.5*d;
        printf("Fine: %.2f rupees",f);
    }
    else if(d>=6 && d<=10){
        f = 1.0*d;
        printf("Fine: %.2f rupees",f);
    }
    else if(d>10 && d<30){
        f = 5.0*d;
        printf("Fine: %.2f rupees",f);
    }
    else if(d>30){
        printf("Membership cancelled");
    }
    else if(d==0){
        printf("No fine.");
    }
    else {
        printf("Invalid input! Days cannot be negative.");
    }
    
    return 0;
}