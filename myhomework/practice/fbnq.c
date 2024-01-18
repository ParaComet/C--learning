#include "stdio.h"
int fbnq(int n,int *x){
    if(n==1||n==2){
        *(x+n)=1;
        return 1;
    }
    *(x+n)=fbnq(n-1,x)+fbnq(n-2,x);
    return *(x+n);
}
/*int stage(int n,int sum){
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    else{
        printf("%d ")
    }
}*/
int main(){
    int n;
    int a[101]={0};
    scanf("%d",&n);
    fbnq(n,a);
    for(int i=1;i<=n;++i){
        printf("%d ",a[i]);
    }
    return 0;
}