#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp=NULL;
char ch='p';
fp=fopen("p.txt","w");
 if (fp==NULL)
    {
        printf("error\n");
        exit(0);
    }
    fputc( ch,fp);
    fclose(fp);
}
