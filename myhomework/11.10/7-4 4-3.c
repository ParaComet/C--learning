#include "stdio.h"
int main(){
    int num=0,x=0,sum;
    scanf("%d",&num);
    sum=num;
    while(num){
        x=x*10+num%10;
        num/=10;
    }
    printf("%s",x==sum?"Yes":"No");
    return 0;
}