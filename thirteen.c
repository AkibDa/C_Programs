#include <stdio.h>
int main(){
    int n,s=0,m,t;
    scanf("%d",&n);
    
    if(n<0){
       m=n*-1; 
       while(m>0){
        t = m%10;
        s = s + t;
        m = m/10;
    }
    printf("Sum of digits: %d",s);
    }
    else {
    m = n;
    while(m>0){
        t = m%10;
        s = s + t;
        m = m/10;
    }
    printf("Sum of digits: %d",s);
    }
    return 0;
}