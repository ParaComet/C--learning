#include <stdio.h>
int main(){
    printf("This is a simple problem.");
    int a;
    a=1-'\0';
    char b='c';
    a=(int)b;
    printf("%c",a);
    return 0;
}