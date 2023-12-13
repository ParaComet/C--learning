//函数被调用的例子如下：
#include<stdio.h>

int mypow(int , int ) ;

int main()
{
    int x, n ;
    
    scanf("%d%d",&x,&n) ;
    printf("%d\n",mypow(x,n)) ;
                
    return 0;
}

/* 请在这里填写答案 */
int mypow(int x,int n){
    int mul=1;
    while(n>0){
        if(n&1==1){
            mul*=x;
        }
        x*=x;
        n>>=1;
    }
    return mul;
}