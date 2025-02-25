#include <stdio.h>
int main(){
    float c,s,p=0;
    
    scanf("%f",&c);
    scanf("%f",&s);
    
    if(c<0 || s<0){
        printf("Invalid input! Prices cannot be negative.");
    }
    else if(s>c){
        p = s - c;
        printf("Profit: %.2f",p);
    }
    else if(c>s){
        p = c - s;
        printf("Loss: %.2f",p);
    }
    else if(c == s){
        printf("No profit, no loss.");
    }
    else {
        printf("Invalid input! Prices cannot be negative.");
    }
    
    return 0;
} 