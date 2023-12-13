#include "stdio.h"
int main(){
    int sum=0,y=0,n=0;
    scanf("%d",&n);
    y=n;
    while(y){
        ++sum;
        y/=10;
    }
    for(int i=1;i<=sum/2;++i){
        if((n%10)!=(n/(int)pow(10,sum-2*i+1))){
            printf("No\n");
            return 0;
        }
        n%=(int)pow(10,sum-2*i+1);
        n/=10;
    }
    printf("Yes\n");
    return 0;
}