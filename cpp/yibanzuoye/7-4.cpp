#include <iostream>
#include <cstring>
using namespace std;
struct puip{
    int age=0;
    char vail='Y';

}; 
puip vis[3];

void sign(int p1,int p2,int typ){
    if(typ==1){
        printf("zhang da zai lai ba");
    }
    else if(typ==2){
        printf("qing %d zhao gu hao %d",p2,p1);
    }
    else if(typ==3){
        printf("huan ying ru guan");
    }
    else{
        printf("%d: huan ying ru guan",p2);
    }
    return ;
}

int main(){

    int lim=0,comp=0,p1=1,p2=2;
    int ty=0;
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d%d",&lim,&comp,&vis[1].age,&vis[2].age);
    if(vis[1].age>vis[2].age){
        p1=2;
        p2=1;
    }
    if(vis[p2].age<lim){
        vis[p1].vail='N';
        vis[p2].vail='N';
        //printf("%d-N %d-N\n",age[1][1],age[1][1]);
        ty=1;
    }
    else if(vis[p1].age<lim&&vis[p2].age>=comp){
        //printf("%d-%c %d-%c\n",age[1][1],age[1][2],age[2][1],age[2][2]);
        ty=2;
    }
    else if(vis[p1].age>=lim){
        //printf("%d-Y %d-Y\n",age[1][1],age[2][1]);
        ty=3;
    }
    else{
        //printf("%d-%c %d-%c\n",age[1][1],age[1][2],age[2][1],age[2][2]);
        vis[p1].vail='N'; 
        ty=4;
    }
    printf("%d-%c %d-%c\n",vis[1].age,vis[1].vail,vis[2].age,vis[2].vail);
    sign(p1,p2,ty);
    return 0;
}
//10-N 15-Y
//2: huan ying ru guan