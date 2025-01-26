#include "stdio.h"
int Gua(int a,int b,int c);
int main(){

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",Gua(a,b,c));
    return 0;
}

int Gua(int a,int b,int c){
    if(a<b){
        int t=a;
        a=b;
        b=t;
    }
    int n=(a-b)*2;
    int ans=-1;
    if(a>n||c>n) return ans;
    ans=(c+(a-b))%n;
    return ans;

}
