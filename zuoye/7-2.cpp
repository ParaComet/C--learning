#include <iostream>
#include <cmath>
using namespace std;
int main(){
    
    double in=0,lim=0;
    int mid=0;
    scanf("%lf%lf",&in,&lim);
    mid=round(in*100/lim)-100;
    if(mid>=50){

        printf("Exceed %d%c. License Revoked",mid,'%');
        return 0;
    }
    
    if(mid>=10){
        printf("Exceed %d%c. Ticket 200",mid,'%');
    }
    else printf("OK");
    
    return 0;
}