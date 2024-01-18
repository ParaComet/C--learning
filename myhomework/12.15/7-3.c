#include "stdio.h"
#include "string.h"
int main(){
    int n=0;
    int len=0;
    char word[111]={0};
    char c1;
    scanf("%d\n",&n);
    while(n--){
        memset(word,0,sizeof(word));
        gets(word);
        scanf("%c\n",&c1);
        len=strlen(word);
        for(int i=0;i<len;++i){
            while(word[i]==c1){
                for(int j=i;j<len;++j){
                    word[j]=word[j+1];
                }
            }
        }
        printf("result: %s\n",word);
    }
    return 0;
}