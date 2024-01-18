#include "stdio.h"
#include "string.h"
int main(){
    int n=0;
    int len=0;
    int c1=0,c2=0;
    int flag=0;
    char word[111]={0};
    char *p[100]={0};
    scanf("%d",&n);
    while(n--){
        memset(word,0,sizeof(word));
        memset(p,0,sizeof(p));
        scanf("%s",word);
        getchar();
        len=strlen(word);
        for(int i=0;i<len;++i){
            if(word[i]=='#'){
                c1++;
                flag=0;
                word[i]='\0';
            }
            else if(flag==0){
                flag=1;
                p[c2++]=word+i;
            }
        }
        printf("%d %d ",c2,c1);
        if(c2==0){
            printf("###\n");
        }
        else{
            for(int i=0;i<c2-1;++i){
                printf("%s ",p[i]);
            }
            printf("%s\n",p[c2-1]);
        }
        c1=0;
        c2=0;
        flag=0;
    } 
    return 0;
}
