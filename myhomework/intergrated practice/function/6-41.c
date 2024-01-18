#include<stdio.h>

int convert(int n);

int main()
{
    int        n ;
    
    scanf("%d",&n);

    printf("%d\n",convert(n)) ;
    return 0 ;    
}

/* 请在这里填写答案 */
int convert(int n){
    if(n==0) return 0;
    //int sum=0;
    return convert(n/10)*2+(n%10);
}