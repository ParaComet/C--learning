#include "stdio.h"
int main(){
    int h[]={1,2,3,4,5,6,7,8,9,10};
    int height[10]={0};
    int num=0;
    for(int i=0;i<10;++i){
        height[i] = h[i];
    }
    int hh=0;
    scanf("%d",&hh);
    for(int i=0;i<10;++i){
        if(hh+30>=height[i]){
            num++;
        }
    }
    printf("%d",num);
    return 0;
}