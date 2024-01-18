#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(){
    int n=0;
    double *po=NULL;
    double max=-1,min=1e4;
    double sum=0;
    scanf("%d",&n);
    po=(double *)malloc(n*sizeof(double));
    for(int i=0;i<n;i++){
        scanf("%lf",po+i);
        if(*(po+i)>max){
            max=*(po+i);
        }
        if(*(po+i)<min){
            min=*(po+i);
        }
        sum+=*(po+i);
    }
    printf("average = %.2lf\nmax = %.2lf",sum/n,max);
    printf("\nmin = %.2lf",min);
    return 0;
}