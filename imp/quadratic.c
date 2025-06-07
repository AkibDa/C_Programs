#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c;
  float d, root1, root2;

  // Input coefficients
  printf("Enter coefficients a, b, and c: ");
  scanf("%f %f %f", &a, &b, &c);

  // Calculate d
  d = b * b - 4 * a * c;

  // Check the nature of the roots
  if (d > 0) {
    // Two real and distinct roots
    root1 = (-b + sqrt(d)) / (2 * a);
    root2 = (-b - sqrt(d)) / (2 * a);
    printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
  }
  else if (d == 0) {
    // Two real and equal roots
    root1 = -b / (2 * a);
    printf("Roots are real and equal: %.2f and %.2f\n", root1, root1);
  }
  else {
    // Complex roots
    float realPart = -b / (2 * a);
    float imagPart = sqrt(-d) / (2 * a);
    printf("Roots are complex and imaginary: %.2f + %.2fi and %.2f - %.2fi\n",
            realPart, imagPart, realPart, imagPart);
  }

  return 0;
}
