#include "stdio.h"
int main(){
    int n=0,sum=0;
    int num=0,time,ti=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&num,&time,&ti);
        if(num){
            sum+=time+(ti-1)*20;
        }
    }
    printf("%d\n",sum);
    return 0;
}
