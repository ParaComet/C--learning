#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char phonenum[0xfff];
    int n=0;
    bool fl=1;
    memset(phonenum,0,sizeof(phonenum));
    while((phonenum[++n]=getchar())!='\n'){
        if(phonenum[n]=='\n'){
            break;
        }
        if(phonenum[n]<'0'||phonenum[n]>'9'){
            fl=0;
        }
    }
    if(phonenum[1]=='1'&&n<=12&&fl){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
/*##12346487*/