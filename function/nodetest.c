#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 0xff
typedef struct node{
    char name[MAXSIZE];
    int data;
    struct node *next;
    struct node *prev;
}tnode,*pnode;
void read(int *x){
    char c=getchar();
    if(c==-1) return ;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        *x=((*x)<<3)+((*x)<<1)+c-'0';
        c=getchar();
    }
    return ;
}
pnode creat(int data){
    pnode head=(pnode)malloc(sizeof(tnode));
    memset(head,0,sizeof(tnode));
    head->data=data;
    head->next=NULL;
    head->prev=NULL;
    return head;
}
void top_insert(pnode head,pnode L){
    pnode temp=head;
    L->next=temp->next;
    L->prev=temp;
    temp->next=L;
    return ;
}
void tail_insert(pnode head,pnode L){
    pnode temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=L;
    L->next=NULL;
    return ;
}
void print(pnode head){
    pnode temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        printf("%d ",temp->data);
    }
    return ;
}
void del(pnode head,int data){
    pnode temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==data){
            pnode t=temp->next;
            temp->next=temp->next->next;
            temp->next->prev=temp;
            free(t);
            return ;
        }
        temp=temp->next;
    }
    return ;
}
void insert(pnode head,int data){
    pnode temp=head;
    while(temp->next!=NULL){
        if(temp->next->data>data){
            pnode L=creat(data);
            L->next=temp->next;
            temp->next=L;
            L->prev=temp;
            return ;
        }
        temp=temp->next;
    }
    pnode L=creat(data);
    temp->next=L;
    L->next=NULL;
    return ;
}
void delall(pnode head){
    pnode temp=head;
    while(temp->next!=NULL){
        pnode t=temp->next;
        temp->next=temp->next->next;
        free(t);
    }
    return ;
}
int main(){
    int xx[MAXSIZE],sum=0;
    //int b=0;
    memset(xx,0,sizeof(xx));
    /*scanf("%d",&b);
    for(int i=0;i<b;++i){
        read(x+sum);
        ++sum;
    }
    /*++sum;
    read(x+sum);*/
    do{
        read(xx+sum);
    }while(xx[sum]&&++sum<MAXSIZE);
    for(int i=0;i<sum;++i){
        printf("%d ",xx[i]);
    }
    printf("\n");
    //printf("%d %d %d",x[sum-1],x[sum],sum);
    pnode head=creat(0);
    for(int i=0;i<sum;++i){
        top_insert(head,creat(xx[i]));
    }
    print(head);
    delall(head);
    return 0;
}
