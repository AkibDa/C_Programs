#include <stdio.h>
int main(){
    int n,a=1,b=1,next,d;
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input! Number of terms must be at least 1.");
    }
    else {
        printf("Fibonacci series:");
        if(n == 1){
            printf("1");
        }
        else{
        printf(" %d %d",a,b);
       for(int i=0;i<n-2;i++){
           d = a;
           a = b;
           b = d+a;
           printf(" %d ",b);
        //   if(i<=1){
        //       next = c;
        //   }
        //   else {
        //       next = sum + 1;
        //       sum = c;
        //       c = next;
        //   }
        //   printf(" %d ",next);
       }}
    } 
    
    
    return 0;
}