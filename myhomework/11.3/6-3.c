#include "stdio.h"
int main(){
    int year=0,tag=0;
    scanf("%d",&year);
    if(year<2001||year>2100){
        printf("Invalid year!\n");
    }
    else{
        for(int i=2001;i<=year;i++){
            if(i%400==0||(i%4==0&&i%100!=0)){
                printf("%d\n",i);
                tag=1;
            }
        }
        if(!tag) printf("None\n");
    }   
    return 0;
}