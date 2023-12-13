#include "stdio.h"
#include "math.h"
int main(){
    int n=0,cnt=0,snake[100][100]={0};
    scanf("%d",&n);
    for(int i=0;i<n/2;++i){
        for(int top=i;top<n-i-1;++top){
            snake[i][top]=++cnt;
        }
        for(int right=i;right<n-i-1;++right){
            snake[right][n-i-1]=++cnt;
        }
        for(int bottom=n-i-1;bottom>i;--bottom){
            snake[n-i-1][bottom]=++cnt;
        }
        for(int left=n-i-1;left>i;--left){
            snake[left][i]=++cnt;
        }
    }
    if(n%2){
        snake[n/2][n/2]=++cnt;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j==n-1){
                printf("%2d",snake[i][j]);;
            }
            else{
                printf("%2d ",snake[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}