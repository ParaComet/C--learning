#include "stdio.h"
int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n/3;++i){
        for(int j=i;j<=(n-i)/2;++j){
            int k=n-i-j;
            if(i+j>k&&i+k>j&&j+k>i){
                ++sum;
                //printf("%d %d %d\n",i,j,k);
            }    
        }
    }
    printf("%d",sum);
    return 0;
}
