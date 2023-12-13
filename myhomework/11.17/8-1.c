#include "stdio.h"
#include "string.h"
int main(){
    int n=0,sum=0;
    int num[21];
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    for(int i=0;i<n*2;++i){
        scanf("%d",&num[i]);
        if(i>=n){
            sum+=num[i]*num[i-n];
        }
    }
    printf("%d",sum);
    return 0;
}