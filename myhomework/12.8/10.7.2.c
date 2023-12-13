#include "stdio.h"
void insertsort(int *l,int *r){
    int temp=0;
    for(int i=0;i<=r-l;++i){
        temp=*(l+i);
        for(int j=i-1;j>=0;--j){
            if(*(l+j)<temp){
                *(l+j+1)=*(l+j);
                *(l+j)=temp;
            }
            else break;
        }
    }
    return ;
}//插入排序在这里
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