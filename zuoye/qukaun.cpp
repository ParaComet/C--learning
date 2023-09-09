//sample
#include "iostream"
using namespace std;
int main(){

    int cot=0,pasw=0;
    double ou=0,res=0;
    (void)scanf("%d%d%lf%lf",&cot,&pasw,&res,&ou);
    if(cot==12345&&pasw==567890){

        if(res<ou){
            printf("余额不足");    
            return 0;
        }
        if(ou>20000){
            printf("超过单次取款限额");    
            return 0;
        }
            printf("取款成功:%.2lf-%.2lf=%.2lf",res,ou,res-ou);
    }
    else{
        printf("帐号或密码错误");
    }
    return 0;
}