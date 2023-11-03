#include "stdio.h"
const int maxn=-0xffffff;
int main(){
    int a=0;
    int max=maxn;
    for(int i=0;i<5;++i){
        scanf("%d",&a);    
        if(a>max) max=a;
    }
    printf("%d",max);
    return 0;
}