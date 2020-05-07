#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int arr[], int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int arr[], int len){
    for(int i = 1; i < len; i++){
        int value = arr[i];
        int j = i;
        while( j > 0 && arr[j - 1] > value){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = value;
    }
}


int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr)/ sizeof(arr[0]);
    print_arr(arr, len);
    insertion_sort(arr, len);
    print_arr(arr, len);
    
}
