//test
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double length,scal,lon;
    scanf("%lF",&length);
    scal=pow(length,2)*sqrt(25+10*sqrt(5));
    scal/=4;
    lon*=5;
    printf("%.4lf\n%lf",scal,lon);
    return 0;

}