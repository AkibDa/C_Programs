#include <stdio.h>
int main(){
    
    int n,rn=0,m=0,t;
    
    scanf("%d",&n);
    
   
    if(n<0 &&(n>-99999 || n<-10000)){
        m = n*-1;
       while(m>0){
           t = m%10;
           rn = (rn*10)+t;
           m = m/10;
       }
       printf("Reversed number: -%d",rn);
    }
    else if(n == -10000){
        printf("Reversed number: -1");
    }
    else if(n>99999 || n<10000){
         printf("Invalid input! Please enter a five-digit number.");
    }
    else {
       m = n;
       while(m>0){
           t = m%10;
           rn = (rn*10)+t;
           m = m/10;
       }
       printf("Reversed number: %d",rn);
    }
    
    return 0;
}