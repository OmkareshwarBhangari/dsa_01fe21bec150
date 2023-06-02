#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct QUEUE
{
    int front;
    int rear;
    int Q[max];
}qu;
void create(qu * q);
int isempty(qu * q);
int isfull(qu *q);
void enqueue(qu *q);
void dequeue(qu *q);
void display( qu *q);
void create(qu * q)
{
    q->front=-1;
    q->rear=-1;

}
int isempty(qu * q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}
int isfull(qu*q)
{ if(q->front == 0 && q->rear == max - 1)
       return 1;
    else
        return 0;


}
void enqueue(qu *q)

{


    if(isfull(q))
        printf("queue full\n");
    else
    {


    if(q->front==-1)
     q->front=0;
     q->rear = (q->rear + 1);
     printf("enter element\n");
     scanf("%d",&q->Q[q->rear]);
    }
}
void dequeue(qu *q)
{
    if(isempty(q))
        printf("queue empty\n");

    else
    {
       int d=q->Q[q->front];
        if (q->front == q->rear) {
      q->front = -1;
      q->rear = -1;
    }
    else

    {
        printf("deleted element is %d\n",q->Q[q->front++]);
    }
}
}
void display(qu*q)
{
    if(isempty(q))
        printf("queue empty\n");
    else
        for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}
int main()
{
    qu q;
    create(&q);
    int choice;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

