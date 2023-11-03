#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 0xff
typedef struct node{
    char name[MAXSIZE];
    int data;
    struct node *next;
}tnode,*pnode;
void read(int *x){
    char c=getchar();
    if(c==-1) return ;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        *x=((*x)<<3)+((*x)<<1)+c-'0';
        c=getchar();
    }
    return ;
}
int main(){
    int xx[MAXSIZE],sum=0;
    //int b=0;
    memset(xx,0,sizeof(xx));
    /*scanf("%d",&b);
    for(int i=0;i<b;++i){
        read(x+sum);
        ++sum;
    }
    /*++sum;
    read(x+sum);*/
    do{
        read(xx+sum);
    }while(xx[sum]&&++sum<MAXSIZE);
    for(int i=0;i<sum;++i){
        printf("%d ",xx[i]);
    }
    //printf("%d %d %d",x[sum-1],x[sum],sum);
    return 0;
}
