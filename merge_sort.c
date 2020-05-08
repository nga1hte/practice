#include <stdio.h>
#include <stdlib.h>

void print_arr(int arr[], int len){
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int left[],int l, int right[],int r, int arr[]){
    int i = 0, j = 0, k = 0;
    while(i < l && j < r){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i < l)
        arr[k++] = left[i++];
    while(j < r)
        arr[k++] = right[j++];
    
}

void mergeSort(int arr[], int len){
    if( len < 2)
        return;
    int mid = len / 2;
    int *left = (int *) malloc(sizeof(int)*mid);  
    int *right = (int *) malloc(sizeof(int)*(len-mid));  
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    for(int i = mid; i < len; i++)
        right[i-mid] = arr[i];
    mergeSort(left, mid);
    mergeSort(right, len - mid);
    merge(left, mid, right, len - mid, arr);
    free(left);
    free(right);
}


int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr)/ sizeof(int);
    print_arr(arr, len);
    mergeSort(arr, len);
    print_arr(arr, len);
    
}
