#include "stdio.h"
int **GetPosition(int a[][4]);
int main(){
    int score[3][4]={{59,60,71,80},
    {80,70,60,59},{59,59,59,59}};
    int **pp;
    pp = GetPosition(score);
    while(*pp){
        printf("%lld\n",(*pp-score[0])/4);
        pp++;
    }
    return 0;
}
int **GetPosition(int a[][4]){
    static int *p[4]={};
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            if(a[i][j]<60){
                p[i] = &a[i][j];
                break;
            }
        }
    }
    return p;
}