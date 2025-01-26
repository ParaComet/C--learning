#include "stdio.h"
#include "stdlib.h"
int main(){
    char comet[7]={0},group[7]={0};
    scanf("%s%s",comet,group);
    int i=0,j=0;
    int cometnum=1,groupnum=1;
    while (comet[i])
    {
        cometnum*=comet[i++]-'A'+1;
    }
    while (group[j])
    {
        groupnum*=group[j++]-'A'+1;
    }
    //printf("%d %d\n",cometnum,groupnum);
    if(cometnum%47==groupnum%47){
        printf("GO\n");
    }
    else{
        printf("STAY\n");
    }
    return 0;
}
