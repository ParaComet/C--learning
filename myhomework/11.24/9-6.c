#include "stdio.h"
#include "string.h"
int main(){
    int li=0,ro=0;
    int len=0;
    char ope[12]={0};
    int num[12]={0};
    scanf("%d %d %s",&li,&ro,ope);
    len=strlen(ope);
    num[0]=li*3+ro+1;
    for(int i=0;i<len;++i){
        li+=1-(ope[i]-'1')/3;
        ro+=(ope[i]-'1')%3-1;
        num[i+1]=li*3+ro+1;
    }
    for(int i=0;i<=len;++i){
        printf("%d",num[i]);
    }   
    return 0;
}