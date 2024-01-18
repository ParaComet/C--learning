#include "stdio.h"
#include "stdlib.h"
double sqrt(double x){
    double l=0,r=x,mid;
    while(r-l>1e-8){
        mid=(l+r)/2;
        if(mid*mid>x) r=mid;
        else l=mid;
    }
    return l;
}
double mpow(double x,int n){
    double ans=1;
    while(n){
        if(n&1) ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}
double nt(double x,int n){
    double te=x;
    while(mpow(te,n)-x>1e-8){
        te-=(mpow(te,n)-x)/(n*mpow(te,n-1));
    }
    return te;
} 
int main(){
    int x,n=0;
    scanf("%d%d",&x,&n);
    printf("%lf\n%lf",nt(x,n),sqrt(x));
    return 0;
}