#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char num[100];
    int fl=0,i;
    memset(num,0,100);
   // num[0]=getchar();
    while((num[fl++]=getchar())!='\n');
    for(i=fl;i>=0;--i){
        putchar(num[i]);
    }
    return 0;
   
}