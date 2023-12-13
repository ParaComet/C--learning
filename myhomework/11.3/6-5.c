#include "stdio.h"
int main(){
    int n,num=0,even=0,odd=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&num);
        if(num%2==0){
            ++even;
        }
        else{
            ++odd;
        }
    }
    printf("%d %d\n",odd,even);
    return 0;
}