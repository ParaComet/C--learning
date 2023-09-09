#include <iostream>
#include <cmath>
using namespace std;
int main(){
    
    double leng=0,tim=0;
    int fee=0;
    scanf("%lf%lf",&leng,&tim);
    
    if(tim>=5){
        fee+=(floor(tim/5))*2;
    }
    if(leng<=3){
        fee+=10;
    }
    else if(leng<=10){
        fee+=round((leng-3)*2)+10;
    }
    else{
        fee+=round((leng-10)*3)+24;
    }
    printf("%d",fee);
    return 0;

}