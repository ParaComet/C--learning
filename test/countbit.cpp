#include <stdio.h>
int main(){
    int x=0;
    int sum=0;
    scanf("%d",&x);
    while(x){
        ++sum;
        x&=x-1;
    }
    printf("%d",sum);
    return 0;
}