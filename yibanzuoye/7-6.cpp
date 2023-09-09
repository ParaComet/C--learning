#include <iostream>
using namespace std;
int main(){
    double pri=0;
    scanf("%lf",&pri);
    if(pri>=1200){
        pri-=400;
    }
    else if(pri>=800){
        pri-=250;
    }
    else if(pri>=400){
        pri-=100;
    }
    printf("最终价格是:%.2lf",pri);
    return 0;
}