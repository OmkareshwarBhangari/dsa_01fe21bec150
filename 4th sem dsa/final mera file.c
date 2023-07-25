#include<stdio.h>

#include<stdlib.h>

#include<time.h>


void main()
{
    int a , b , number=0;

    printf("enter the numbers (range)\n\n");

    scanf("%d%d" ,&a,&b);

    FILE *fp=NULL;

    srand(time(NULL));

    number=(rand() % (b - a +1)) + a;

    printf("%d\n",number);

    fp=fopen("abcc.txt","w");

    if (fp==NULL)
    {
        printf("error\n");
        exit(0);
    }

    fprintf(fp,"%d",number);

    fclose(fp);
}
