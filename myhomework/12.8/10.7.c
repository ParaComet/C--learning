#include "stdio.h"
#include "string.h"
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}   
int cha(int *x,int *y,int *z){
    if(x>y) swap(x,y);
    if(y>z) swap(y,z);
    if(x<y) swap(x,y);
    return 0;
}
void insertsort(int *l,int *r){
    int temp=0;
    for(int i=0;i<=r-l;++i){
        temp=*(l+i);
        for(int j=i-1;j>=0;--j){
            if(*(l+j)>temp){
                *(l+j+1)=*(l+j);
                *(l+j)=temp;
            }
            else break;
        }
    }
    return ;
}//插入排序在这里   
void quicksort(int *l,int *r){
    int *ll,*rr;
    ll=l;
    rr=r;
    int tag=0;
    for(int i=0;i<r-l;++i){
        if(*(l+i)>*(l+i+1)){
            tag=1;
            break;
        }
    }
    if(tag){
        if(r-l<=50){
            insertsort(l,r);
            return ;
        }
        int *mid;
        mid=((r-l)>>1)+l;
        swap(l,mid);
        while(rr>ll){
            while(*rr>=*l&&ll<rr) --rr;
            while(*ll<=*l&&ll<rr) ++ll;
            swap(ll,rr);
        }
        swap(l,ll);
        if(l<ll) quicksort(l,ll);
        if(ll+1<r) quicksort(ll+1,r);
    }
    return ;
}
int main(){
    int n=0;
    int num[100700]={0};
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&num[i]);
    }
    quicksort(num,num+n-1);
    for(int i=0;i<n-1;++i){
        printf("%d ",num[i]);
    }
    printf("%d\n",num[n-1]);
    return 0;
}