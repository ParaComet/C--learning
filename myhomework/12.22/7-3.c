#include "stdio.h"
#include "string.h"
int main(){
    int n=0;
    char word[111]={0};
    char *po[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        memset(word,0,sizeof(word));
        scanf("%s",word);
        getchar();
        for(int j=0;j<7;j++){
            if(strcmp(word,po[j])==0){
                printf("%d\n",j+1);
                printf("%s\n",po[j]+1);
                break;
            }
            if(j==6){
                printf("-1\n");
            }
        }
    }
    return 0;
}
/*
1
Monday
*/