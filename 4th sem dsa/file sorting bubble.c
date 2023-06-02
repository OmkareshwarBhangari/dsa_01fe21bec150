#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

// Function to generate n random numbers within given range
void generate_random_numbers(int n, int start_range, int end_range ) {
    //srand(time(NULL)); // Seed the random number generator
    FILE *fp;
    int a[max];
    for (int i = 0; i < n; i++) {
       int randnum = rand()%end_range+start_range;
       printf("\t%d\t",randnum);

       fp = fopen("input.txt", "w");
       fprintf(fp, "%d\n", randnum);

    }

    fclose(fp);
}
void display(int arr[max],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d \t",n);

    }
}
void bubblesort(int arr[],int n)
{
    int i,j,swap;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]>arr[j])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }

        }
    }
}
int main() {
    int n, start_range, end_range;
    int arr[max],count=0,temp;

    // Get input from user
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the start of the range: ");
    scanf("%d", &start_range);
    printf("Enter the end of the range: ");
    scanf("%d", &end_range);
    generate_random_numbers( n, start_range, end_range );

    printf("\nRandom numbers written to input.txt\n");

    FILE *input,*output;
    input=fopen("input.txt","r");
    if (input == NULL) {
        printf("Error opening input file!");
        exit(1);
    }
    printf("\nnow reading for outpuy\n");
        while(fscanf(input,"%d",&temp)==1)
    {

        arr[count]=temp;
        count++;
    }
    fclose(input);
    printf("\nread all the elemnts");
     bubblesort(arr,count);
     display(arr,count);
     output=fopen("output.txt","w");
     for(int i=0;i<count;i++)
     {
         fprintf(output,"%d",arr[i]);
     }
     fclose(output);
     printf("\n writter to output");

    return 0;
}


