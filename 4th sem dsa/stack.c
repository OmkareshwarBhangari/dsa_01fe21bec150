#include<stdio.h>
#define max 5
main()
{
    int stack[max];
    int top=0;
    int *a=&top;
    int choice;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push(stack,a);
            break;
        case 2:
            pop(stack,a);
            break;
        case 3:
            display(stack,a);
            break;
        case 4:
            exit(0);
        }
    }
}
void push(int stack[max],int *top)
{
    if(*top==max)
    {
       printf("stack is full\n");
       return ;
    }
    //*top=*top+1;
    printf("enter element\n");
    scanf("%d",&stack[*top]);
    *top=*top+1;
}
void pop(int stack[max],int *top)
{
    if(*top==0)
    {
        printf("stack is empty");
        return ;
    }
    *top=*top-1;
    printf("%d is the removed element\n",stack[*top]);
    //*top=*top-1;
}
void display(int stack[max],int*top)
{
    if(*top==0)
    {
        printf("empty stack");

    }
    else
    {
        for(int i=*top-1;i>-1;i--)
        {
            printf("%d ",stack[i]);
        }

    }
}
