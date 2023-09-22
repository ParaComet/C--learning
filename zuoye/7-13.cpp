#include <iostream>
using namespace std;
int main(){
    int num=0;
    scanf("%d",&num);
    int shu[num+1][4];
    for(int i=0;i<num;++i){
        scanf("%d %d %d",&shu[i][0],&shu[i][1],&shu[i][2]);
        //shu[i][3]=i+1;
    }
    for(int i=0;i<num;++i){
        if(shu[i][2]==shu[i][0]*shu[i][1]){
            printf("Lv Yan\n");
        }
        else if(shu[i][2]==shu[i][0]+shu[i][1]){
            printf("Tu Dou\n");
        }
        else{
            printf("zhe du shi sha ya!\n");
        }
    }
    return 0;   
}