#include "stdio.h"
#include "stdlib.h"
void mov(int *x,int n,int m){
    int *po=(int *)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        *(po+i)=*(x+i+n-m);
    }
    for(int i=n-m;i>0;--i){
        *(x+i+m-1)=*(x+i-1);
    }
    for(int i=0;i<m;++i){
        *(x+i)=*(po+i);
    }
}
int main(){
    int n=0,m=0;
    int num[12]={0};
    scanf("%d%d",&n,&m);
    //int *po=(int *)malloc(m*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",num+i);
    }
    mov(num,n,m);
    printf("After move:");
    for(int i=0;i<n;i++){
        printf(" %d",*(num+i));
    }
    return 0;    
}