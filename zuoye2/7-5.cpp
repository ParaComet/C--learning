#include <iostream>
#include <cmath>
using namespace std;   
const int fuckpta=0xfffff;
int nn=0;

int poo(int x,int n){
    int sum=1;
    for(int i=0;i<n;++i){
        sum*=x;
    }
    return sum;
}
void judge(int sum){
    int fk=0;
    int fkk=sum;
    for(int i=nn;i>0;--i){
        fk+=poo(sum%10,nn);
        sum/=10;
        if(fk>fkk){
            return;
        }
    }
    if(fk==fkk){
        printf("%d\n",fkk);
    }
    return;
}

/*void daffodils(int result,int n){
    int g=1;
    if(n!=nn){
        g=0;
    }
    for(int i=g;i<=9;i++){
        daffodils(result*10+i,n-1);
    }
    return;
}*/

int main(){
    scanf("%d",&nn);
    for(int j=poo(10,nn-1);j<poo(10,nn);++j){
        judge(j);
    }
    //daffodils(0,nn);
    return 0;
}