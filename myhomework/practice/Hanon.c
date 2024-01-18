#include "stdio.h"
int Hanon(int n,int a,int b,int c){
    if(n==1){
        printf("plate%d:%d->%d\n",n,a,c);
        return 1;
    }
    else{
        int sum=0;
        sum+=Hanon(n-1,a,c,b);
        printf("plate%d:%d->%d\n",n,a,c);
        sum+=Hanon(n-1,b,a,c)+1;
        return sum; 
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("times = %d",Hanon(n,1,2,3));
    return 0;
}