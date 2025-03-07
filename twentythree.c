#include <stdio.h>
int main(){
    double n,m; 
    int c;
    printf("Enter two numbers:");
    scanf("%lf %lf\n",&n,&m);
    printf("Select an operation:\n1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    if(n==0 || m==0){
        printf("Division by zero is not allowed.");
    }
    else {
        switch(c){
        case 1:
            printf("Sum: %0.2lf",n+m);
        break;
        case 2:
            printf("Difference: %0.2lf",n-m);
        break;
        case 3:
            printf("Product: %0.2lf",n*m);
        break;
        case 4:
            printf("Quotient: %0.2lf",n/m);
        break;
        default:
            printf("Invalid operation! Please enter a number between 1 and 4.");
        
    }
    }
    
    return 0;
}