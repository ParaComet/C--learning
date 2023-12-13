#include "stdio.h"
int judge(int x){
    int tag=0;
    if(x%400==0||(x%4==0&&x%100!=0)) tag=1;
    return tag;
}
int main(){
    int year=0,mon=0,day=0;
//    int test=0;
    scanf("%d%d",&year,&mon);
    if(mon<8){
        day=mon%2==0?30:31;
        if(mon==2) day=judge(year)?29:28;
    }
    else{
        day=mon%2==0?31:30;
    }
    printf("%d\n",day);
    return 0;
}