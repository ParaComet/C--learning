#include "stdio.h"
int main(){
    int n=0,sum=0;
    int num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&num);
        while(num!=-1){
            if(num%3==1&&num%5==2){
                sum+=num;
            }
            scanf("%d",&num);
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}