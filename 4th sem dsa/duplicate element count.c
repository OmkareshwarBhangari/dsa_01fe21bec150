# include<stdio.h>
#define size 5

void read(int a[size], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void display(int a[size],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void lin_search(int a[size],int n,int key)
{
    int i,count=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==key)
               {
                   count++;
               }
        }
        if(count!=0)
            printf("\n Duplicate element found %d times \n",count);
        else
        printf("element is not present");
}
main()
{
    int n,key,a[size];
    printf("enter no of elemets   ");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    printf("\nenter element to be searched\t");
    scanf("%d",&key);
    lin_search(a,n,key);

}
