#include<stdio.h>

int getMax(int arr[], int n){
    int i, max = arr[0];
    for(i=1;i<n;i++){
        if(arr[i] > max)
        max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp){
    int output[n + 1];
    int max = (arr[0] / exp) % 10;
    for(int i = 1; i < n; i++){
        if(((arr[i] / exp) % 10) > max)
        max = arr[i];
    }
    int count[max+1];
    for(int i = 0; i < max; i++){
        count[i] = 0;
    }
    for(int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    for(int i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] -1] = arr[i];
        count[(arr[i / exp]) % 10]--;
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);
    int i;
    for(i = 1;max / i > 0 ;i *= 10){
        countingSort(arr, n, i);
    }
}

void printArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

int main(){
    int arr[5] = {123, 541, 399, 442, 119};
    radixSort(arr, 5);
    printArray(arr, 5);
}