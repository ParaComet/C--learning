#include <iostream>
#include <cmath>
using namespace std;

int yue(int m,int n){
    int x=1,y=1,mid=0;
    x=max(m,n);
    y=min(m,n);
    while(x%y){
        mid=x%y;
        x=y;
        y=mid;
    }
    return y;
}
int gon(int x,int y){
    int mid=x;
    while(mid%y){
        mid+=x;
    }
    return mid;
}
int main(){
    int m=0,n=0;
    scanf("%d %d",&m,&n);
    printf("%d %d",yue(m,n),gon(m,n));
    return 0;
}