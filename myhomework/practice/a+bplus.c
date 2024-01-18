#include "stdio.h"
#include "string.h"
int main(){
    
    char a[120]={0};
    char b[120]={0};
    char c[120]={0};
    int len1=0,len2=0;
    int i=0,j=0;
    int flag=0;
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    while(a[len1]!='\0'){
        len1++;
    }
    while(b[len2]!='\0'){
        len2++;
    }
    for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--){
        c[i]=a[i]+b[j]-'0'+flag;
        if(c[i]>'9'){
            c[i]-=10;
            flag=1;
        }
        else{
            flag=0;
        }
    }
    for(;i>=0;i--){
        c[i]=a[i]+flag;
        if(c[i]>'9'){
            c[i]-=10;
            flag=1;
        }
        else{
            flag=0;
        }
    }
    for(;j>=0;j--){
        c[j]=b[j]+flag;
        if(c[j]>'9'){
            c[j]-=10;
            flag=1;
        }
        else{
            flag=0;
        }
    }
    printf("%s",c);
    return 0;
}
//123
// 321 scanf("%[^\n]")