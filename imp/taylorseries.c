#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define ACCURACY 1e-6

double Radians(double d){
    return d * (PI/180.0);
}

double Taylor(double x){
    double t = x, s = x;
    int n=1;
    
    while(fabs(t)>ACCURACY){
        t *= -1 * x * x / ((2 * n) * (2 * n + 1));
        s += t;
        n++;
    }
    return s;
}

int main(){
    printf(" x (degrees)   sin(x)\n");
    printf("----------------------\n");
    
    for(int x=0;x<=360;x+=15){
        double r = Radians(x);
        double v = Taylor(r);
        printf("%4d          %.6f\n", x,v);
    }
    return 0;
}