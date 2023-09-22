#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double fuckpta=1e-6; 
    double i=1,fl=1;
    double e=1,fir=0;
    scanf("%lf",&fir);

    while((pow(fir,i))/fl>fuckpta){
        e+=pow(fir,i)/fl;
        fl*=(++i);
    }

    printf("%.4lf",e);
    return 0;
}