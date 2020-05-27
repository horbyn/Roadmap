#include <stdio.h>

void bubble_sort(int *arr, int arr_size){
    int swap;

    for(int i = 0; i < arr_size - 1; i++)
        for(int j = 0; j < arr_size - i; j++)
            if(arr[j] > arr[j + 1]){
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
}

int main(){
    int arr[] = {12, 35, 99, 18, 76};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, arr_size);

    printf("The sequences in incremental order: ");
    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}