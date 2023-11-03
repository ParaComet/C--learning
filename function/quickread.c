#include "stdio.h"
#include "string.h"
const int MaxSize=0xffff;
void quickread(int *x){
    char c=getchar();
    if(c==-1) return ;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        *x=((*x)<<3)+((*x)<<1)+c-'0';
        c=getchar();
    }
    return ;
}
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
    int num[MaxSize];
    int sum=0;
    memset(num,0,sizeof(num));
    do{
        quickread(num+sum);
    }while(num[sum]&&++sum<MaxSize);
    quicksrt(num,num+sum-1);
    for(int i=0;i<sum;++i){
        printf("%d ",num[i]);
    }
    return 0;
}