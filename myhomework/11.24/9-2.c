#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int main(){
    char str[200];
    char cat[200];
    int num=0,len=0,tag=1;
    memset(str,0,sizeof(str));
    memset(cat,0,sizeof(cat));
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len-1;++i){
        if(str[i]=='A'){
            tag=-1;
        }
        else{
            num=num*10+'K'-str[i];
        }
    }
    if(str[len-1]=='M'){
        printf("%dW",num*tag*11-23173);
    }    
    else{
        printf("%dM",(num*tag+23173)/11);
    }
    return 0;
}
/*
AJKM
-23283W
*/