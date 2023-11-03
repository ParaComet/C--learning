#include "stdio.h"
int main(){
    int dd;
    char cc;
    double f1,f2;
    scanf("%lf%d %c %lf",&f1,&dd,&cc,&f2);
    printf("%c %d %.2lf %.2lf",cc,dd,f1,f2);
    return 0;
}