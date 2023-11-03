#include <stdio.h>
#include <string.h>
void read(int *x){
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        *x=((*x)<<3)+((*x)<<1)+c-'0';
        c=getchar();
    }
    return ;
}
int main(){   
    int a=0,b[777];
    memset(b,0,sizeof(b));  
    scanf("%d",&a);
    ++a;
    read(b+a);
    printf("%d %d",a,b[a]);
    /*double a = 0.8, b = 3.8, c = 12.8, d = 231.8, e = 9035.8;
    printf("%022.17f\n", a);
    printf("%022.17f\n", b);
    printf("%022.17f\n", c);
    printf("%022.17f\n", d);
    printf("%022.17f\n", e);*/
    return 0;
}