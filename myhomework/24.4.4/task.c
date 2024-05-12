#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
    int data=0;
    struct ListNode *head=NULL;
    struct ListNode *tail=NULL;
    while (scanf("%d",&data))
    {
        if(data!=-1)
        {
            struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
            newnode->data=data;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
        }
        else
        {
            break;
        }
    } 
    return head;
}

struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode *p;
    struct ListNode *t=(struct ListNode *)malloc(sizeof(struct ListNode));
    t->next=head;
    p=t;
    while((p->next)!=NULL)
    {
        if((p->next->data)%2==0)
        {
            struct ListNode *temp=p->next;
            p->next=temp->next;
            free(temp);
        }
        else
        {
            p=p->next;
        }
    }
    return t->next;
}