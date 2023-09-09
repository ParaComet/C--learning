#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int num=0,wen[4],i=0,sum=0,ori;
    scanf("%d",&num);
    ori=num;
    memset(wen,0,sizeof(wen));
    while(num%10!=0){
        wen[++i]=num%10;
        num/=10;
        sum+=pow(wen[i],3);
    }
    if(i!=3){
        printf("请输入一个三位数");
        return 0;
    }
    if(sum==ori){
        printf("%d是水仙花数",ori);
    }
    else{
        printf("%d不是水仙花数",ori);
    }
    return 0;
}