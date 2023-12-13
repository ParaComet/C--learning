//函数被调用例子如下：
#include<stdio.h>

int reverseNum(int) ; 

int main()
{
    int        num ;

    scanf("%d",&num);
    printf("The reverse form of number %d is %d.\n",num,reverseNum(num)) ;

    return 0;
}

/* 请在这里填写答案 */
//函数原型如下：
int reverseNum(int n){
    int num=0;
    while(n){
        num=num*10+n%10;
        n/=10;
    }
    return num;
}