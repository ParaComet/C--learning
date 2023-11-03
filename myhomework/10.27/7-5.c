#include "stdio.h"
int main(){
    double a;
    scanf("%lf",&a);
    if(a<0){
        printf("%.2lf",a*a+9);
    }
    else printf("%.3lf",a*a*a+5);
    return 0;
}