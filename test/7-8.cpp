#include <iostream>
#include <cstring>
using namespace std;
struct club{
    int mem=0;
    string name={};
}cl[5];

void def(){
    cl[1].name="Competition department";
    cl[2].name="Office";
    cl[3].name="Organization Department";
    cl[4].name="Propaganda Department";
} 
inline void swa(club *a,club *b){
    club t=*a;
    *a=*b;
    *b=t;
    return ;
}
int main(){
    int len=0;
    char in[0xfffff];
    memset(in,0,sizeof(in));
    memset(cl,0,sizeof(cl));
    while((in[len++]=getchar())!='\n');
    //int len=strlen(in);
    for(int i=0;i<len;++i){
        if(in[i]=='A'){
            ++cl[1].mem;
        }
        if(in[i]=='B'){
            ++cl[4].mem;
        }
        if(in[i]=='C'){
            ++cl[2].mem;
        }
        if(in[i]=='D'){
            ++cl[3].mem;
        }
    }
    def();
    for(int i=4;i>0;--i){
        for(int j=1;j<i;++j){
            if(cl[j].mem<cl[j+1].mem){
                swap(cl[j],cl[j+1]);
            }
        }
    }
    for(int i=1;i<=4;++i){
        //if(cl[i].mem!=0){
            printf("%s %d people!\n",cl[i].name.c_str(),cl[i].mem);
        //}
    }
    return 0;
}