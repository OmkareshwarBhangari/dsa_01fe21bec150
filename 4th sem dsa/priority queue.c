#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    int priority;
    struct NODE *next;
}*node;
node createnode()
{
    node t;
    t=(node*)malloc(sizeof(struct NODE));
    printf("enter element\n");
    scanf("%d",&t->data);
    printf("enter priority\n");
    scanf("%d",&t->priority);
    t->next=NULL;
    return t;
}
node insertrear(node head,node t)
{
    node cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=t;
    return head;
}
node insertfront(node head,node t)
{
    t->next=head;
    return t;
}
node enqueue(node head)
{
    node t;
    t=createnode();
    if(head==NULL)
        return t;
    node cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    if(t->priority>cur->priority)
        return insertrear(head,t);
   if(t->priority<head->priority)
        return insertfront(head,t);
    cur=head;
    node prev=NULL;
    while(cur!=NULL&&(cur->priority<t->priority))
    {
        prev=cur;
        cur=cur->next;
    }
    t->next=prev->next;
    prev->next=t;
    return head;

}

node dequeue(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("queue underflow\n");
        return head;
    }
    printf("%d is the deleted element\n",cur->data);
    head=head->next;
    free(cur);
    return head;
}
void display(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("queue underflow\n");
        return head;
    }
    while(cur!=NULL)
       {
           printf("%d ",cur->data);
           cur=cur->next;
       }
    printf("\n");
}
int main()
{
    node head=NULL;
    int choice;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=enqueue(head);
            break;
        case 2:
            head=dequeue(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        }
    }
}

