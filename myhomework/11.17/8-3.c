#include "stdio.h"
int main(){
    int n=0,sum=0,maxx=0;
    int temp,last=-1;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&temp);
        if(temp>last){
            last=temp;
            ++sum;
        }
        else{
            last=temp;
            sum=1;
        }
        maxx=maxx>sum?maxx:sum;
    }
    printf("%d",maxx);
    return 0;
}