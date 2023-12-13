#include "stdio.h"
#include "string.h"
char str[1024]={0};
int judge(char *poi,int len){
    for(int i=0;i<len/2;++i){
        if(poi[i]!=poi[len-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    char str2[1024]={0};
    int len=0;
    gets(str);
    len=strlen(str);
    for(int i=len;i>0;--i){
        for(int j=0;j<=len-i;++j){
            memset(str2,0,sizeof(str2));
            strncpy(str2,str+j,i);
            if(judge(str2,i)){
                printf("%d",i);
                return 0;
            }
        }
    }
}