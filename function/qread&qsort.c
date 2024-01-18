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
    if(*x>*y) swa(x,y);
    if(*y>*z) swa(y,z);
    if(*x<*y) swa(x,y);
    return ;
}
void insertsort(int *l,int *r){
    for(int *i=l+1;i<=r;++i){
        int temp=*i;
        int *j=i-1;
        while(j>=l&&*j>temp){
            *(j+1)=*j;
            j--;
        }
        *(j+1)=temp;
    }
    return;
}   
void quicksrt(int *l,int *r){
    if(l>=r) return;
    int *i=l,*j=r;
    int tag=0;
    for(int *k=l;k<r;++k){
        if(*k>*(k+1)){
            tag=1;
            break;
        }
    }
    if(tag==0) return;
    if(r-l<80){
        insertsort(l,r);
        return;
    }
    cha(l,r,(r-l)/2+l);
    int temp=*l;
    while(i<j){
        while(i<j&&*j>=temp) j--;
        if(i<j) *i=*j;
        while(i<j&&*i<=temp) i++;
        if(i<j) *j=*i;
    }
    *i=temp;
    qsort(l,i-1);
    qsort(i+1,r);
    return;
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