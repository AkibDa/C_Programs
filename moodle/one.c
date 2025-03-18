#include<stdio.h>
int main() {
    int a,b,c,d,e,A;
    float P;
    
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if(a>100||a<0||b>100||b<0||c>100||c<0||d>100||d<0||e>100||e<0){
        printf("Invalid input! Marks should be between 0 and 100.");
    }
    else {
        A = (a+b+c+d+e);
        P = ((A*1.0)/500)*100;
        printf("Aggregate Marks: %d\n",A);
    }
    return 0;
    }