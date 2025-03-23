#include <stdio.h>
int main(){
    int n,count=0;
    scanf("%d",&n); 
    if(n>1){
        for(int i=1;i<=n;i++){ 
         if(n%i==0){
            count++;         
            }
        }
        if(count ==  2){
        printf("%d is a prime number.",n); 
        }
        else {
            printf("%d is not a prime number.",n);
        } 
    }
    else {
        printf("Invalid input! Number should be greater than or equal to 2.");
    }
    return 0;
}