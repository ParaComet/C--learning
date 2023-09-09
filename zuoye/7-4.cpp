#include <iostream>
using namespace std;
int runn(int x,int y,int fl){
    int num=0,mid=0,xx=0;
    x-=1;
    if(x<2){
        num=31;
    }
    else if(x<8){
        num=(x%2)*31+(x/2)*61-fl+y;
    }
    else{
        xx=x-7;
        num=(7%2)*31+(7/2)*61-fl+y+(xx%2) *31+(xx/2)*61;
    }
    return num;
}   
int main(){
    int ye,mon,da;
    scanf("%d/%d/%d",&ye,&mon,&da);
    //printf("%d %d %d\n",7/2,mon,da);
    if(ye%400==0){
        printf("%d",runn(mon,da,1));
    }
    else if((ye%4==0)&&(ye%100!=0)){
        printf("%d",runn(mon,da,1));
    }
    else{
        printf("%d",runn(mon,da,2));
    }
    return 0;
}