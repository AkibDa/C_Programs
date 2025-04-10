#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input! Decimal number must be non-negative");
    }
    else {
        int p=1, rem;
        int bin=0;
        
        while(n!=0){
            rem=n%2;
            n/=2;
            if(rem==0){
                p*=10;
            }
            else {
                p*=10;
                bin+=p*rem;
            }
        }
        bin/=10;
        printf("Binary equivalent: %d", bin);
    }
    
    return 0;
}