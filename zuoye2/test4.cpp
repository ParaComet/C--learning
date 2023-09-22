#include <iostream>
using namespace std;
int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(j>(n/2)+1-i&&j<(n/2)+1+i&&i<=n/2+1){
                printf("* ");
            }
            else if(j>i-n/2-1&&j<=n-i+n/2+1&&i>n/2+1){
                printf("* ");
            }
            else{
                printf("  ");
            }
            }
            printf("\n"); 
        }
    return 0;
}
