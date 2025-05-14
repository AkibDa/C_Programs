#include<stdio.h>

typedef struct {
    double real;
    double imagine;
} complex;

int main(){
  complex c1 = {.real = 1.0, .imagine = 2.0};
  complex c2 = {.real = 3.0, .imagine = 4.0};

  complex sum;

  sum.real = c1.real + c2.real;
  sum.imagine = c1.imagine + c2.imagine;
  printf("Sum: %.2f + %.2fi\n", sum.real, sum.imagine);
  printf("Size of complex struct: %zu bytes\n", sizeof(complex));
  printf("Size of double: %zu bytes\n", sizeof(double));
}