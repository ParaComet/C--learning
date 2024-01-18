#include "stdio.h"
#include "string.h"
int len(char *str){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}
void strmcpy(char *str1,char *str2,int t){
    int len=0;
    while(str2[len]!='\0'){
        len++;
    }
    for(int i=0;i<len-t;++i){
        str1[i]=str2[t+i];
    }
    str1[len-t]='\0';
}
int main(){
    char str2[1024]={0};
    char s[500]={0};
    int n=0;
    int t=0;
    scanf("%d",&n);
    while(n--){
        memset(str2,0,sizeof(str2));
        getchar();
        gets(str2);
        scanf("%d",&t);
        if(t>len(str2)){
            printf("error input\n");
            continue;
        }
        strmcpy(s,str2,t-1);
        printf("%s\n",s);
    }
    return 0;
}