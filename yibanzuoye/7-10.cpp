#include <iostream>
#include <cstring>
using namespace std;

int dat[0xff][4],T=0;

bool runn(int x);

int qie(int day,int sp){
    if(day+2<=sp){
        return 0;
    } 
    return 1;
}

int qie1(int day,int sp){
    if(day+2>sp){
        return day+2-sp;
    }
    return day+2;
}

void prin(int ye,int mo,int dy,int dd){
    printf("%d-%.2d-%.2d\n",ye,mo+qie(dy,dd),qie1(dy,dd));
    return ;
}

void miao(int x,int y,int z){
    if(y<8){
        if(y==2){
            prin(x,y,z,28+runn(x));
            //printf("%d-%.2d-%.2d",x,y+qie(z,28+runn(x)),qie1(z,28+runn(x)));
        }
        else{
            prin(x,y,z,30+(y%2));
            //printf("%d-%.2d-%.2d",x,y+qie(z,30+(y%2)),qie1(z,30+(y%2)));
        }
        
    }
    else if(y<12){
        prin(x,y,z,31-(y%2));
        //printf("",x,y+qie(z,),qie1(z,));
    }
    else{
        if(z>29){
            prin(x+1,0,z,31);
        }
        else{
            prin(x,y,z,31);
        }
    }
    return ;
}

int main(){
    
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%d-%d-%d",&dat[i][0],&dat[i][1],&dat[i][2]);
    }
    for(int j=0;j<T;++j){
        miao(dat[j][0],dat[j][1],dat[j][2]);
    }
    return 0;
}
bool runn(int x){
    if((x%4==0&&x%100!=0)||x%400==0){
        return 1;
    }
    else return 0;
}
//010
//2023-12-31 printf 2100 2000 2024-01-02
