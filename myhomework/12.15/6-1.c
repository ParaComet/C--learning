#include <stdio.h>
void fun(char *s);
int main()
{
char a[80],*s;
s=a;
gets(s);
fun(s);
printf("the result: %s\n", s);
return 0;
}

/* 请在这里填写答案 */
void fun(char *s){
    while(*s!='\0'){
        if(*s>='1'&&*s<='9'){
            *s='#';
        }
        s++;
    }
}