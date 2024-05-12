#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"

#define ERROR -1
#define Num 54
#define StackSize 5

typedef struct card
{
    char suit;
    char num;
    struct card *next;
}Card;

typedef struct Slist
{
    Card pack[Num];
    int length; 
}SL,*SList;

typedef struct Node
{
    Card data;
    struct Node *next;
    struct Node *prior;
}LNode, *LinkList;

typedef struct Snode
{
    Card *data;
    int top;
}stack,*Stack;

typedef struct Squeue
{
    Card *data;
    int front;
    int rear;
    int size;
}queue,*Queue;

SList initSL(int n); //初始化顺序表
LinkList initLinkList();
Stack initStack(int n);
void insert(LinkList LL, Card e);
Card draw(SList L, int n);
void print(LinkList LL);
void print2(SList L);
void FindJoker(LinkList LL,Stack S,Queue Q,int M);
void Push(stack *S, Card e);    //入栈
Queue CreateQueue(int MaxSize); //创建队列
void EnQueue(Queue Q, Card e);  //入队

char suit[4] = {'A', 'B', 'C', 'D'};
char num[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

int main()
{
    int M=0;
    scanf("%d",&M);
    time_t t;
    srand((unsigned)time(&t));
    SList L = initSL(Num);
    LinkList L1 = initLinkList(), L2 = initLinkList();
    //print2(L);
    Stack S = initStack(Num);
    while(L->length)
    {
        insert(L1, draw(L, 1));
    }
    //print(L1);
    Queue Q = CreateQueue(StackSize);
    FindJoker(L1,S,Q,M);
    print(L1);
    printf("The Last 5 Aces: \n");
    for(int i = 0; i < StackSize; i++)
    {
        printf("%c %c\n", Q->data[(i+Q->front)%Q->size].suit, 
                Q->data[(i+Q->front)%Q->size].num);
    }
}

SList initSL(int n)
{
    int i, j;
    SList L = (SList)malloc(sizeof(SL));
    L->length =n;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            L->pack[i*13+j].suit = suit[i];
            L->pack[i*13+j].num = num[j];
        }
    }
    L->pack[52].suit = 'X';
    L->pack[52].num = 'X';
    L->pack[53].suit = 'Y';
    L->pack[53].num = 'Y';
    for(i = 0; i < 54; i++)
    {
        L->pack[i].next = NULL;
    }
    return L;
}

LinkList initLinkList()
{
    LinkList LL = (LinkList)malloc(sizeof(LNode));
    LL->next = LL;
    LL->prior = LL;
    return LL;
}

Stack initStack(int n)
{
    Stack S = (Stack)malloc(sizeof(stack));
    S->data = (Card *)malloc(n*sizeof(Card));
    S->top = -1;
    return S;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct Squeue));
    Q->data = (Card *)malloc(MaxSize * sizeof(Card));
    Q->front = 0;
    Q->rear = 0;
    Q->size = MaxSize;
    return Q;
}

void insert(LinkList LL, Card e)
{
    LinkList p, q;
    p = LL;
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    while(p->next != LL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
    q->next = LL;
    LL->prior = q;
}

Card draw(SList L, int n)
{
    int i, j;
    Card e;
    i = rand()%L->length;
    e = L->pack[i];
    for(j = i; j < L->length-1; j++)
    {
        L->pack[j] = L->pack[j+1];
    }
    L->length--;
    return e;
} 

void print(LinkList LL)
{
    LinkList p;
    p = LL->next;
    while(p != LL)
    {
        printf("%c %c\n", p->data.suit, p->data.num);
        p = p->next;
    }
}

void print2(SList L)
{
    int i;
    for(i = 0; i < L->length; i++)
    {
        printf("%c %c\n", L->pack[i].suit, L->pack[i].num);
    }   
}

void FindJoker(LinkList LL,Stack S,Queue Q,int M)
{
    LinkList p,temp;
    p = LL->next;
    temp = LL;
    while(p != LL)
    {
        if((p->data.suit == 'X' && p->data.num == 'X') 
            || (p->data.suit == 'Y' && p->data.num == 'Y'))
        {
            break;   
        }
        p = p->next;
    }
    if(p == LL)
    {
        printf("No Joker\n");
    }
    else
    {
        printf("Joker found\n");
    }
    while(temp->next->next != LL)
    {
        for(int j = 0; j < M; j++)
        {
            p = p->next;
        }
        if(p == LL)
        {
            p = p->next;
        }
        if((p->data.suit == 'X' && p->data.num == 'X') 
            || (p->data.suit == 'Y' && p->data.num == 'Y'))
        {
            int i = 5;
            while(i--&&S->top!=-1)
            {
                insert(LL, S->data[S->top--]);
            }
        }
        Push(S, p->data);
        if(p->data.suit == 'A')
        {
            EnQueue(Q, p->data);
        }
        LinkList T;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        T = p;
        p = p->next;
        free(T);
    }

}

void EnQueue(Queue Q, Card e)
{
    if((Q->rear+1)%Q->size == Q->front)
    {
        Q->data[Q->front] = e;
        Q->front = (Q->front+1)%Q->size;
        Q->rear = (Q->rear+1)%Q->size;
    }
    else
    {
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear+1)%Q->size;
    }
}

void Push(stack *S, Card e)
{
    S->data[++S->top] = e;
}

// Path: Exp2/card.c