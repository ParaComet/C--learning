#include "iostream"
#include "cstring"
using namespace std;
int main(){
    int tre[0xffff];
    int length=0,n=0,l,r,num=0;
    memset(tre,0,sizeof(tre));
    scanf("%d%d",&length,&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;++j){
            tre[j]=1;
        }
    }
    while(length+1){
        num+=!tre[length];
        --length;
    }
    printf("%d",num);
    return 0;
}