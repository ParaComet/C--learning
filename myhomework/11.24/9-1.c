#include "stdio.h"
#include "string.h"
int main(){
    char str[120];
    int num[129];
    int len=0;
    memset(num,0,sizeof(num));
    memset(str,0,sizeof(str));
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            ++num[(int)str[i]];
        }
        if(str[i]>='a'&&str[i]<='z'){
            ++num[(int)str[i]];
        }
    }
    for(int i='A';i<='Z';i++){
        if(num[i]){
            printf("The character %c has presented %d times.\n",i,num[i]);
        }
    }
    for(int i='a';i<='z';i++){
        if(num[i]){
            printf("The character %c has presented %d times.\n",i,num[i]);
        }
    }
}