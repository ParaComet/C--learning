#include <iostream>
#include <cstring>
using namespace std;
int in[0xfffff];

inline void swa(int &a,int &b){
    int t=a;
    a=b;
    b=t;
    return ;
}
inline void cha(int l,int m,int r){
    if(in[l]>in[m]){
        swa(in[l],in[m]);
    }
    if(in[m]>in[r]){
        swa(in[m],in[r]);
    }
    if(in[l]<in[m]){
        swa(in[l],in[m]);
    }
}

inline void quicksrt(int l1,int r1){
    int l=l1,r=r1,tag=1;
    for(int i=l1;i<r1;++i){
        if(in[i]>in[i+1]){
            tag=0;
            break;
        }
    }
    if(tag==0){
        int mid=(l+r)/2;
        cha(l,mid,r);
        int fl=in[l];
        while(l<r){
            while(fl<=in[r]&&l<r){
                --r;
            }
            while(fl>=in[l]&&l<r){
                ++l;
        }                              
        swa(in[l],in[r]);
        }
        swa(in[l1],in[l]);
        if(l1<l){
            quicksrt(l1,l);
        }
        if(l+1<r1){
            quicksrt(l+1,r1);
        }
    }
    return;
}

int main(){
    int sum=0;
    int fll=0;
    memset(in,0,sizeof(0));
    scanf("%d",&fll);
    /*while(scanf("%d",&in[sum])){
        if(getchar()=='\n'){
            break;
        }
        ++sum;    
    }*/
    for(int i=0;i<fll;++i){
        scanf("%d",&in[i]);
    }
    quicksrt(0,fll-1);
    for(int i=0;i<fll;++i){
        printf("%d ",in[i]);
    }
    return 0;
}