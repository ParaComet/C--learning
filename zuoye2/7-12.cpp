#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int fkpta=0;
    int fl=0;
    while((scanf("%d",&fkpta))){
         fl++;
        if(fkpta==250){
            break;
        }
    }
    printf("%d",fl);
    return 0;
}
