#include <stdio.h>

int main() {
    int a = 10;
    int* p = &a; // Pointer to a
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", (void*)&a);
    printf("Value of p: %p\n", (void*)p);
    printf("Value pointed to by p: %d\n", *p);
    
    *p = 20; // Change value of a using pointer
    printf("New value of a: %d\n", a);
    
    return 0;
}
// Output:
// Value of a: 10
// Address of a: 0x16bd26d78
// Value of p: 0x16bd26d78
// Value pointed to by p: 10
// New value of a: 20