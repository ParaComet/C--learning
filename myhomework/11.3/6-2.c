#include "stdio.h"
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(fabs((a-b)-c)<1e-6){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}