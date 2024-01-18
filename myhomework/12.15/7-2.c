#include "stdio.h"
#include "string.h"
int main(){
    int n=0;
    char s[20]={0};
    gets(s);
    if(strcmp(s,"red")==0){
        n=1;
    }
    if(strcmp(s,"yellow")==0){
        n=3;
    }
    if(strcmp(s,"blue")==0){
        n=2;
    }
    if(strcmp(s,"green")==0){
        n=4;
    }
    if(strcmp(s,"black")==0){
        n=5;
    }
    if(n==0){
        printf("Not Found");
    }
    else{
        printf("%d",n);
    }
    return 0;
}