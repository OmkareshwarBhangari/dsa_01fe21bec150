#include<stdio.h>
#include<stdlib.h>
#define rowsize 10
#define colsize 10


void read(int*mat,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
         scanf("%d",(mat + i*col + j));
        }
    }
}
void display(int*mat, int row,int col)
{
    int i ,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
         printf("%d \t", *(mat + i*col + j));
        }
        printf("\n");
    }
}
void multiply(int *mat1,int*mat2,int*res,int r1,int r2,int c1,int c2)
{
    int i,j;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
           *((res+i)+j)=0;
        }
    }
    for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1;k++)
        {
            *(res+i*c2+j) += *(mat1+i*c1+k) * *(mat2+k*c2+j);
         }
      }
   }

}
int main() {
   int mat1[rowsize][colsize], mat2[rowsize][colsize], res[rowsize ][colsize], r1, c1, r2, c2;
   printf("Enter rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and column for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   // Taking input until
   // 1st matrix columns is not equal to 2nd matrix row
   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }
   printf("enter matrix 1\n");
    read( mat1,r1,c1);
    display(mat1,r1,c1);
    printf("enter matrix 2\n");
    read(mat2,r2,c2);
    display(mat2,r2,c2);
    printf("\n");
    multiply(mat1,mat2,res,r1,r2,c1,c2);
    display(res,r1,c2);
    return 0;
    }

