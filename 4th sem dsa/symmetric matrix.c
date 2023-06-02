#include<stdio.h>
main()
{
    int arr[10][10],n,m;
    printf("\nEnter the number of rows:");
    scanf("%d",&n);
    printf("\nEnter the number of coloumn:");
    scanf("%d",&m);
    read(arr,n,m);
    display(arr,n,m);
    printf("\n\n");
    symmetric(arr,n,m);


}
void read(int a[10][10],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[10][10],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void symmetric(int a[10][10],int n,int m)
{
    if(n!=m)
   {
       printf("not a symmetric matrix\n");
       exit(0);
   }
    int t[10][10],i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            t[j][i]=a[i][j];
        }
    }
   //if(n!=m)
   //{
     //  printf("not a symmetric matrix\n");
       //exit(0);
   //}
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(t[i][j]!=a[i][j])
            {
                printf("not a symmetric matrix\n");
                exit(0);
            }
        }
    }
    printf("symmetric matrix\n");

}
