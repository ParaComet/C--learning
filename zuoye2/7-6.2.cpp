#include <iostream>
using namespace std;

bool judge(int n){
    if(n%5==1&&n%6==5&&n%7==4&&n%11==10){
        printf("%d",n);
        return false;
    }
    return true;
}
int main(){
    int n=0;
    while(judge(n++));
    return 0;
}