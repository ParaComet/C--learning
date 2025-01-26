#include "stdio.h"
int main(){
    int height[10]={0};
    int h=0,num=0;
    for(int i=0;i<10;++i){
        scanf("%d",height+i);
    }
    scanf("%d",&h);
    for(int i=0;i<10;++i){
        if(h+30>=height[i]){
            num++;
        }
    }
    printf("%d",num);
    return 0;
}