#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;

};
typedef struct Node *node;
node CreateNode()
{
    node t;
    int ele;
    t=(node*)malloc(sizeof(struct Node));
     if(t==NULL)
    {
        printf("\nNot Created\n");
        exit(0);
    }
    printf("\nEnter integer value:");
    scanf("%d",&ele);
    t->data=ele;
    t->next=NULL;
    return t;
}
void display_list(node first)
{
    node t;
    if(first==NULL)
    {
        printf("\nEmpty List/Stack");
        return;
    }
    printf("\nElements are:\n");
    t=first;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}
node insert_rear(node head)
{
    node t,c;
    t=CreateNode();
    if(head==NULL)
       {

       return t;
       exit(0);}
    c=head;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=t;
    return head;
}
node delete_front(node head)
{
    node cur;
    cur=head;
    head=head->next;
    printf("Node Deleted:\n");
    printf("%d",cur->data);
    free(cur);
    return head;
}
main()
{
    node head=NULL;
    int ch;
    while(1)
    {
        printf("\n1-push\n2-pop\n3-display\n4-exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1:head=insert_rear(head);
            break;

            case 2:head=delete_front(head);
            break;

            case 3:display_list(head);
            break;

            case 4: exit(0);
        }
    }
}
