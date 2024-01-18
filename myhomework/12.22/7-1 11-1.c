#include "stdio.h"
#include "stdlib.h"
typedef struct{
    char num[25];
    char name[25];
    int score[6];
    double aver;
}stu;
void insertsort(stu *p,int n){
    int temp=0;
    for(int i=0;i<n;++i){
        temp=p->score[i];
        for(int j=i;j>0;--j){
            if(p->score[j-1]<temp){
                p->score[j]=p->score[j-1];    
                p->score[j-1]=temp;
            }
            else break;
        }
    }
    return ;
}
int main(){
    //double aver=0;
    stu *p=(stu *)malloc(sizeof(stu));
    p->aver=0;
    gets(p->name);
    gets(p->num);
    for(int i=0;i<5;++i){
        scanf("%d",p->score+i);
        p->aver+=p->score[i];
    }
    insertsort(p,5);
    printf("Name:%s\n",p->name);
    printf("ID:%s\n",p->num);
    printf("Score:");
    for(int i=0;i<4;++i){
        printf("%d ",p->score[i]);
    }
    printf("%d\n",p->score[4]);
    printf("average:%.2lf total:%.0lf\n",(p->aver)/5,(p->aver));
    free(p);
    return 0;
}