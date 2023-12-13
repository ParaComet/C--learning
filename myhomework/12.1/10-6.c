#include "stdio.h"
int main(){
    int n=0;
    int oe=0;
    char str[11][33]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    for(int j=0;j<n;j++){
        scanf("%d",&oe);
        printf("%s\n",str[oe]);
    }
    return 0;
}