#include <iostream>
#include <cstring>
using namespace std;

struct tea{
    int score=0;
    int win=0;
    int in=0;
    int num=0;
    //string name={};
}team1[0xfff];

inline void swap(tea *a,tea *b){
    tea t=*a;
    *a=*b;
    *b=t;
    return ;
}

void superbubble(int tteam){
    tea *p=team1;
    for(int i=tteam;i>0;--i){
        for(int j=1;j<i;++j){
            if(p[j].score<p[j+1].score){
                swap(p+j,p+j+1);
            }
            else if(p[j].score==p[j+1].score){
                if(p[j].win<p[j+1].win){
                    swap(p+j,p+j+1);
                }
                else if(p[j].win==p[j+1].win){
                    if(p[j].in<p[j+1].in){
                        swap(p+j,p+j+1);
                    }
                    else if(p[j].in==p[j+1].in){
                        if(p[j].num>p[j+1].num){
                            swap(p+j,p+j+1);
                        }
                    }
                }
            }
        }
    }
    return ;
}

void nmsl(int t1,int t2,int s1,int s2){
    team1[t1].num=t1;
    team1[t2].num=t2;
    team1[t1].in+=s1;
    team1[t2].in+=s2;
    team1[t1].win+=s1-s2;
    team1[t2].win+=s2-s1;
    return ;
}

void prin(int tteam){
    for(int i=1;i<=tteam;++i){
        printf("%d",team1[i].num);
        if(i!=tteam) printf(" ");
    }
    return;
}
int main(){
    int group=0;
    scanf("%d",&group);
    for(int i=1;i<=group;++i){
        int t1=0,t2=0,s1=0,s2=0;
        int team=0;
        memset(team1,0,sizeof(team1));
        scanf("%d",&team);
        for(int j=1;j<=team*(team-1)/2;++j){
            scanf("%d%d%d%d",&t1,&t2,&s1,&s2);
            if(s1>s2){
                team1[t1].score+=3;
            }   
            else if(s1==s2){
                team1[t1].score+=1;
                team1[t2].score+=1;
            }
            else{
                team1[t2].score+=3;
            }
            nmsl(t1,t2,s1,s2);
        }
        superbubble(team);
        prin(team);
        if(i!=group) printf("\n");
    }

    return 0;
}//1 4 1 2 0 2 1 3 1 1 1 4 0 0 2 3 2 0 2 4 4 0 3 4 2 2