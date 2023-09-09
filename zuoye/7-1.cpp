#include <iostream>
using namespace std;
int main(){
    double usE=0,mid=0;
    scanf("%lf",& usE);
    if(usE>=0){
        
        if(usE<=50){
            printf("cost = %.2lf",usE*0.53);
        }
        else{
            mid=(usE-50)*0.58+50*0.53;
            printf("cost = %.2lf",mid);
        }
        
    }
    else printf("Invalid Value!");
    return 0;
}
//cost = 5.30