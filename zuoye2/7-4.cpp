#include <iostream>
#include <cstring>
using namespace std;

void fen(int money,int qua,int las);
int a[7][0xfffff],count=1;

int main(){
    int num=0;
    memset(a,0,sizeof(a));
    scanf("%d",&num);
    fen(num,5,5);
    for(int i=1;i<count;i++){
        printf("fen5:%d, fen2:%d, ",a[5][i],a[2][i]);
        printf("fen1:%d, total:%d\n",a[1][i],a[0][i]);
    }
    printf("count = %d",count-1);
    return 0;   
}

void fen(int money,int qua,int las){
    if(qua==1){
        a[qua][count]=money;
        a[0][count]+=a[5][count]+a[2][count]+a[1][count];
        count++;
    }
    else{
        for(int i=money/qua;i>0;i--){
            if(money-i*qua>0){
                a[qua][count]=i;
                fen(money-i*qua,qua/2,qua);
            }
            if(!a[las][count]){
                a[las][count]=a[las][count-1];
            }
        }
    }
    return;
}