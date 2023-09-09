#include <iostream>
#include <cstring>
using namespace std;
int main(){
    /*char tim[10],i=0;
    memset(tim,0,sizeof(tim));
    while((tim[i++]=getchar())!=0);*/
    int hou=0,minu=0;
    scanf("%d:%d",&hou,&minu);
    if(minu>59){
        printf("Value for minutes must be in the range 0 to 59");
        return 0;
    }
    if(hou>23){
        printf("Value for hours must be in the range 0 to 23");
        return 0;
    }
    if(hou>12){
        printf("%.2d:%.2d(PM)",hou-12,minu);
    }
    else if(hou==12){
        printf("%.2d:%.2d(noon)",hou,minu);
    }
    else if(hou==0){
        printf("%.2d:%.2d(AM)",hou+12,minu);
    }
    else{
        printf("%.2d:%.2d(AM)",hou,minu);
    }
    return 0;
}