#include <stdio.h>

void quick_sort(int *arr, int head, int tail){
    int swap, pivot = arr[head];        // 第一个元素作为基准
    int i = head, j = tail;

    if(tail - head + 1 < 2)    return;  // 只有0/1个元素的数组必然是有序的

    while(i != j){
        while(arr[j] >= pivot && i < j)    j--;
        while(arr[i] <= pivot && i < j)    i++;

        if(i != j){
            // 退出循环时若ij未相遇说明
            // 要么基准左边数字比基准大
            // 要么基准右边数字比基准小
            // 因此需要交换
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }
    // ij相遇时与基准交换
    arr[head] = arr[i];
    arr[i] = pivot;

    // 继续对基准左边和右边的两堆数排序
    quick_sort(arr, head, i - 1);
    quick_sort(arr, i + 1, tail);
}

int main(){
    int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr, 0, arr_size - 1);

    printf("The sequences in incremental order: ");
    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}