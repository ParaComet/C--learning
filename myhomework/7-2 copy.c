#include <stdio.h>
int main(){
    int *a,*b;
    int xx[12];
    a=xx;
    b=xx+5;
    scanf("%d",&xx[1]);
    printf("%d",b-a);
    //scanf("%d-%d-%d",&a,&b,&c);
    //printf("%d",a+b);
    //printf("temperature:%d\nhumidity:%d",a,b);
    //printf("%d-%02d-%02d",c,a,b);
    return 0;
}