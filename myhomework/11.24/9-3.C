#include "stdio.h"
#include "string.h"
int main(){
    int n=0,sum=0;
    int ver[10]={7,9,10,5,8,4,2,1,6,3};
    char ver2[12]="10X98765432";
    char id[22]={0};
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",id);
        for(int i=0;i<17;++i){
            if(id[i]=='X'){
                sum+=10*ver[i%10];
                continue;
            }
            sum+=(id[i]-'0')*ver[i%10];
            sum%=11;
        }
        if(ver2[sum]==id[17]){
            printf("right\n");
        }   
        else{
            printf("wrong\n");
        }
        sum=0;
    }
    return 0;
}