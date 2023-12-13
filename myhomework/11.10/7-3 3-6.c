#include "stdio.h"
int main(){
    int row=0,line=0;
    scanf("%d%d",&row,&line);
    for(int i=0;i<row;++i){
        for(int j=1;j<=line*2+1;++j){
            printf("%s",j%2==0?"*****":"|");
        }
        printf("\n");
        for(int j=1;j<=line*2;++j){
            printf("%s","|  ");
        }
        printf("%s","|\n");
        for(int j=1;j<=line*2+1;++j){
            printf("%s",j%2==0?"--+--":"|");
        }
        printf("\n");
        for(int j=1;j<=line*2;++j){
            printf("%s","|  ");
        }
        printf("%s","|\n");
    }
    for(int j=1;j<=line*2+1;++j){
        printf("%s",j%2==0?"*****":"|");
    }
    return 0;
}