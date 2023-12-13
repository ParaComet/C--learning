#include <stdio.h>
void swa(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
int main(){
    printf("This is a simple problem.\n");
    int ggg=123;
    int gg=3210;
    //*p=10x12345678;
    int aa[3];
    aa[0]=1;
    aa[1]=2;
    swa(aa,aa+1);
    printf("%d %d\n",aa[0],aa[1]);
    printf("%d\n",'\13');
    //printf("%c",*p);
    printf("\n%c",'A'+'6'-'3');
    return 0;
}