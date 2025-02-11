#include <stdio.h>

int main() {
    float basic_salary, da, hra, gross_salary;
    
    printf("Enter the basic salary: ");
    scanf("%f", &basic_salary);
    
    da = 0.40 * basic_salary;
    
    hra = 0.20 * basic_salary;
    
    gross_salary = basic_salary + da + hra;
    
    printf("Gross salary: %.2f\n", gross_salary);
    
    return 0;
}
