#include "stdio.h"
int mypow(int x,int n){
    int ans=1;
    while(n){
        if(n&1)
            ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}
int main(){
    int n=0;
    int x=0;
    scanf("%d%d",&x,&n);
    printf("%d",mypow(x,n));
    return 0;
}