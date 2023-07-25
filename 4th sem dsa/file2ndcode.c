#include <stdio.h>

void bubble_sort(int arr[100], int n);

int main() {
    int arr[100];
    int i = 0;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while(fscanf(fp, "%d", &arr[i]) != EOF) {
        i++;
    }

    fclose(fp);

    printf("Array read from file: ");
    for(int j=0; j<i; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    bubble_sort(arr,i);
    printf("Array sorted from file: ");
    for(int j=0; j<i; j++) {
        printf("%d ", arr[j]);
    }

    fp = fopen("output.txt", "w");
    for(int j=0; j<i; j++) {
        fprintf(fp,"%d", arr[j]);
    }
    fclose(fp);

    return 0;
}
void bubble_sort(int arr[100], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
