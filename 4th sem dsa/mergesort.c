#include<stdio.h>

void swap(int* a, int* b) {

    int temp;

    temp = *a;

    *a = *b;

    *b = temp;

}

 int partition(int* arr, int low, int high) {

    int pivot = arr[high]; // Last element is the pivot

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {

        // Compares each element from the beginning with the pivot (last element)

        // If the value is less than the pivot, swaps it with the element at position i+1

        if (arr[j] < pivot) {

            i++;

            swap(&arr[i], &arr[j]);

        }

    }

   // After all the swaps are done, swaps the pivot with the element at position i+1

    swap(&arr[i + 1], &arr[high]);

    return i + 1;

}

 void quicksort(int* arr, int low, int high) {

    int pi;

    if (low < high) {

        // pi is the partition index - arr[pi] is now at the right place

        pi = partition(arr, low, high);

   // Recursively sorts the left and right halves of the partitioned array

        quicksort(arr, low, pi - 1); // for left half

        quicksort(arr, pi + 1, high); // for right half

    }

}

 int main() {

    int arr[] = { 3, 4, 1, 2, 5 };

   printf("Initial array: ");

    for (int i = 0; i < 5; i++) {

        printf("%d\t", arr[i]);

    }

    printf("\n");

    quicksort(arr, 0, 4);

    printf("Sorted array: ");

    for (int i = 0; i < 5; i++) {

        printf("%d\t", arr[i]);

    }
    return 0;
}
