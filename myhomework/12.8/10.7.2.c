#include "stdio.h"
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
//插入排序在这里
int main(){
    int n=0;
    int a[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    insertsort(a,a+n-1);
    for(int i=0;i<n-1;++i){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
    return 0;
}