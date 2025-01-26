#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(){
    int n=0;
    scanf("%d",&n);
    int *cute=(int *)malloc(n*sizeof(int)),
        *num=(int *)malloc(n*sizeof(int));
    memset(num,0,n*sizeof(int));
    memset(cute,0,n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%d",cute+i);
    }
    for(int i=0;i<n;++i){
        for(int j=i-1;j>=0;--j){
            if(cute[i]>cute[j]){
                num[i]++;
            }
        }
        printf("%d ",num[i]);
    }
}