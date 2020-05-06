#include <stdio.h>

int sl_search(int arr[], int len , int val){
    int last = arr[len];
    arr[len] = val;
    int i = 0;
    while(arr[i] != val)
        i++;
    arr[len] = last;
    if( i < len || arr[len] == val)
        return i;
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int find = 9;
    int len = sizeof(arr) / sizeof(arr[0]);
    int index = sl_search(arr, len - 1 , find);
    printf("The value %d is found in index: %d\n", find, index);
    return 0;
}
