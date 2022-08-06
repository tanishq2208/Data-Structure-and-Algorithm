// NOT WORKING ---->countingSort() function is not working.
#include<stdio.h>

int max_func(int arr[], int n){
    int i, max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max)
        max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int output[], int n){
    int i, max;
    max = max_func(arr, n) + 1;
    int count[max];

    for(i = 0; i < max; i++){
        count[i] = 0;
    }
    
    for(i = 0; i < max; i++){
        count[arr[i]]++;
    }

    for(i = 1; i< max; i++){
        count[i] += count[i-1];
    }

    for(i=0;i<n;i++){
        output[count[arr[i]] - 1 ] = arr[i];
    }
    return;
}

void print(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    return;
}

int main(){
    int arr[7] = {4, 2, 2, 8, 3, 3, 1};
    int output[7];
    
    countingSort(arr, output, 7);
    print(output, 7);
}