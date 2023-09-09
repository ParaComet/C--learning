//test
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double length,scal;
    int lon;
    scanf("%lF",&length);
    scal=pow(length,2)*sqrt(25+10*sqrt(5));
    lon=length*5;
    printf("%.4lf\n%d",scal,lon);
    cout.setf(ios::fixed);
    cout<<'\n'<<setprecision(2)<<scal;
    return 0;

}
