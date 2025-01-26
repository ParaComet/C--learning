#include <iostream>
using namespace std;
int main(){
    int aran[0xffff];
    int sum=0;
    while(scanf("%d",&aran[++sum])){
        if(getchar()=='\n'){
            break;
        }
    }
    for(int i=sum;i>0;--i){
        //cout<<aran[i]<<" ";
        int flag=0;
        for(int j=1;j<i;++j){
            if(aran[j]>aran[j+1]){
                swap(aran[j],aran[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
        else if(flag==1)
        {
            for(int i=1;i<=sum;++i){
                printf("%d ",aran[i]);
            }
            printf("\n");
        }
    }
    for(int i=1;i<=sum;++i){
        printf("%d ",aran[i]);
    }
    return 0;
}