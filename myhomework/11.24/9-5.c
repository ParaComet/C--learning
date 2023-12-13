#include "stdio.h"
#include "string.h"
int main(){
    int num[11]={0};
    int len=0;
    char str[1024]={0};
    scanf("%s",str);
    len=strlen(str);
    while(len--){
        ++num[str[len]-'0'];
    }
    for(int i=0;i<10;++i){
        if(num[i]){
            printf("%d:%d\n",i,num[i]);
        }
    }
    return 0;
}