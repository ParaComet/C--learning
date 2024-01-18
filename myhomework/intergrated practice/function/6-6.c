//设计了辅助函数后，函数被调用的例子如下：
#include<stdio.h>

void bubbleSort(int a[],int n);

//输出数组中所有元素 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[10010] ;
    
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    bubbleSort(num,n) ; 
    outputData(num,n) ;
    return 0 ;
}


/* 请在这里填写答案 */
void outputData(int data[],int elementCount){
    for(int i=0;i<elementCount-1;++i){
        printf("%d ",data[i]);
    }
    printf("%d\n",data[elementCount-1]);
    return;

}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
void cha(int *x,int *y,int *z){
    if(*x>*y) swap(x,y);
    if(*y>*z) swap(x,z);
    if(*x<*y) swap(x,y);
}
void insort(int *l,int *r){
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
void qsort(int *l,int *r){
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
        insort(l,r);
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
void bubbleSort(int data[],int n){
    qsort(data,data+n-1);
    return;
}