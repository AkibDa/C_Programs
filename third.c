#include <stdio.h>
int main(){
    double dist;
    double m,f,i,c;
    scanf("%lf",&dist);
    if(dist<0.0){
        printf("Invalid input. Distance cannot be negative. \n");
    }
    else {
        m = dist * 1000;
        f = dist * 3280.84;
        i = dist * 39370.1;
        c = dist * 100000;
        printf("Distance in meters: %.2lf\n",m);
    }
    return 0;
}