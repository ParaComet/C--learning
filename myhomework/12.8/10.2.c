
#include<stdio.h>

#define LSIZE 81

void strDelete( char str[], int dBegin, int dLen) ;

int main()

{

    char    str[LSIZE];
    int        dBegin, dLen;

    scanf("%s" , str );
    scanf("%d%d", &dBegin, &dLen);
    strDelete(str, dBegin, dLen);
    printf("%s\n", str);

    return 0;

}

/* 请在这里填写答案 */
void strDelete( char str[], int dBegin, int dLen){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    int len=i;
    for(int j=dBegin+dLen;j<len;j++){
        str[j-dLen]=str[j];
    }
    str[len-dLen]='\0';
}