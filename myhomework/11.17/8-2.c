#include "stdio.h"
#include "string.h"
#include "math.h"
void swa(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
void cha(int *x,int *y,int *z){
    if(x>y) swa(x,y);
    if(y>z) swa(y,z);
    if(x<y) swa(x,y);
    return ;
}
void quicksrt(int *l,int *r){
    int tag=0;
    int *ll,*rr;
    ll=l;
    rr=r;
    for(int i=0;i<r-l;++i){
        if(*(l+i)>*(l+i+1)){
            tag=1;
            break;
        } 
    }
    if(tag){
        int *mid;
        mid=((r-l)>>1)+l;
        cha(l,mid,r);
        while(rr>ll){
            while(*rr>=*l&&ll<rr) --rr;
            while(*ll<=*l&&ll<rr) ++ll;
            swa(ll,rr);
        }
        swa(l,ll);
        if(l<ll) quicksrt(l,ll);
        if(ll+1<r) quicksrt(ll+1,r);
    }
    return ;
}
int main(){
    int n=0,sum=0;
    int num[101];
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&num[i]);
    }
    quicksrt(num,num+n-1);
    for(int i=ceil(n/2.0);i<n;++i){
        sum+=num[i]/2;
    }
    printf("%d",sum);
    return 0;
}