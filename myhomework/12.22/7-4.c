#include "stdio.h"
int main(){
    char str[100]={0};
    int n=0;
    scanf("%s",str);
    while(str[n]!='\0'){
        ++n;
    }
    for(int i=0;i<n;++i){
        while(str[i]=='a'){
            for(int j=i;j<n;++j){
                str[j]=str[j+1];
            }
            --n;
        }
    }
    printf("%s",str);
    return 0;
}