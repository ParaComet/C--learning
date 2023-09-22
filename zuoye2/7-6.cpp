#include <iostream>
using namespace std;
int main(){
    //int fl=0;
    double sum=0,n=0,dm=2,fk=1,mid=0;
    scanf("%lf",&n);
    for(int i=1;i<=n;++i){
        sum+=dm/fk;
        mid=dm;
        dm=mid+fk;
        fk=mid;
    }
    printf("%.2lf",sum);
    return 0;
}