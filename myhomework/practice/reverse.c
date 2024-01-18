#include "string.h"
#include "stdio.h"
#include "stdlib.h"
int judge(char x){
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
        return 1;
    return 0;
}
void cpy(char *te,char *wo,int be,int en,int len){
    for(int i=0;i<=en-be;++i){
        te[len-en+i-1]=wo[be+i];
    }
}
int main(){
    int flag=0;
    char wo[1300]={0};
    char be[1200];
    char en[1200];
    int num=0;
    gets(wo);
    int len=0;
    len=strlen(wo);
    for(int i=0;i<len;++i){
        if((wo[i+1]=='#'||wo[i+1]==0)&&flag==1){
            flag=0;
            en[num]=i;
            ++num;
        }
        else if(judge(wo[i])&&flag==0){
            be[num]=i;
            flag=1;
        }
    }
    char *temp=(char *)malloc(sizeof(char)*len);
    memset(temp,0,sizeof(char)*len);
    for(int i=0;i<len;++i){
        temp[i]=wo[len-1-i];
    }
    /*printf("%s\n",temp);
    printf("%d\n",num);
    for(int i=0;i<num;++i){
        printf("%d %d\n",be[i],en[i]);
    }*/
    for(int i=0;i<num;++i){
        cpy(temp,wo,be[i],en[i],len);
    }
    temp[len]=0;
    printf("%s",temp);
    return 0;
}
/*
question:#in#apple%&^^&%###pineapple#
ni#:noitseuq
08
*/