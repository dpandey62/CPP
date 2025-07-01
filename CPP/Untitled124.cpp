#include<stdio.h>
#include<stdlib.h>

int max_sum(int arr[], int n, int k) {
    
    if(k > n) {
        printf("Invalid window size\n");
        return -1;
    }

   
    int window_sum = 0;
    for(int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

   
    int max_sum = window_sum;

    
    for(int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];  
        if(window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    return max_sum;
}

int main() {
    int n = 6, k = 3;
    int arr[] = {16, 12, 9, 19, 11, 8};

    printf("Maximum sum of %d consecutive elements is: %d\n", k, max_sum(arr, n, k));
    return 0;
}

