#include <stdio.h>

void intToRoman(int n){
    if(n<1 || n>1000){
        printf("Invalid input! Enter a number between 1 and 1000.\n");
        return ;}
    struct RomanNumeral{
        int val;
        char *c;
    }
    numerals[] = {{1000, "M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4, "IV"}, {1,"I"}};
    printf("The Roman numeral is: ");
    for(int i=0;i<13;i++){
        while(n>=numerals[i].val){
            printf("%s",numerals[i].c);
            n -= numerals[i].val;
        }
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    intToRoman(n);
    return 0;
}