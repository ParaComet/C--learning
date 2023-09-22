#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
struct book{
    int num;
    char opr;
    int time[4];
    bool fl=0;
};
struct book bk[12][0xffff];
double ton[12][5];
int jie[0xffff][5];

int main(){
    int N=0,fg=0,xx=1,yy=0;
    int b=0,c=0,d=0;
    char ch;
    memset(bk,0,sizeof(bk));
    memset(ton,0,sizeof(ton));
    memset(jie,0,sizeof(jie));
    scanf("%d\n",&N);
    while(xx<=N){
        scanf("%d",&b);
        if(b==0){
            ++xx;
            //yy=0;
        }
        scanf(" %c %d:%d\n",&ch,&c,&d);
        if(b!=0){
            bk[xx][b].fl=!bk[xx][b].fl;
        }
        if(ch=='S'&&b!=0){
            bk[xx][b].time[1]=c*60+d;
        }
        else if(b!=0){
            bk[xx][b].time[2]=c*60+d;
            if(b!=0&&!bk[xx][b].fl){
                bk[xx][b].time[3]=bk[xx][b].time[2]-bk[xx][b].time[1];
                ton[xx][0]++;
                ton[xx][1]+=bk[xx][b].time[3];
            }
        }
    }
    for(int i=1;i<=N;++i){ 
        if(ton[i][0]!=0){
            fg=round(ton[i][1]/ton[i][0]);
        }
        else{
            fg=0;
        }
        yy=ton[i][0];
        printf("%d %d\n",yy,fg);
        
    }
    /*for(int j=1;j<=N;++j){
        printf("%lf %lf\n",ton[1][j],ceil(ton[2][j]/ton[1][j]));
    }*/
    return 0;
}/*
3
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00*/