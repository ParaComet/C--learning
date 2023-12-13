#include "stdio.h"
int main(){
    int n=0,num,line=0,rowt=0,row;
    int min,max=0x80000000;
    //printf("%d\n",max);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        min=0x7fffff;
        for(int j=0;j<n;++j){
            scanf("%d",&num);
            if(num<min){
                min=num;
                rowt=j;
            }
        }
        if(max<min){
            max=min;
            line=i;
            row=rowt;
        }
    }
    printf("%d %d %d",max,line,row);
    return 0;
}
/*
3
4 5 6
8 7 9
1 2 3*/