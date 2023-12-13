//函数被调用的例子如下：
#include<stdio.h>

int    getDays(int,int) ;

int main()
{
    int    year, month ;
    
    scanf("%d%d",&year,&month);
    printf("There are %d days in month %d year %d.",getDays(year,month), month, year) ;

    return 0 ;    
}

/* 请在这里填写答案 */
int getDays(int ye,int month){
    int day=0;
    int flag=0;
    if((ye%4==0&&ye%100!=0)||ye%400==0){
        flag=1;
    }
    if(month<8){
        day=month%2==0?30:31;
        return month==2?28+flag:day;
    }
    else{
        day=month%2==0?31:30;
        return day;
    }
}