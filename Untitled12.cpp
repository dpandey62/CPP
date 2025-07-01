#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Frame {
    int frameno;
    char fingerprint[10];
};

struct Frame arr[10];
int n;

void sort() {
    int i, j;
    struct Frame temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].frameno > arr[j + 1].frameno) {
                // Swap the frames
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Example usage
    n = 3; // Number of frames
    
    // Initialize the array with some values
    arr[0].frameno = 2;
    strcpy(arr[0].fingerprint, "abc");
    
    arr[1].frameno = 1;
    strcpy(arr[1].fingerprint, "def");
    
    arr[2].frameno = 3;
    strcpy(arr[2].fingerprint, "ghi");
    
    // Sort the frames
    sort();
    
    // Print sorted frames
    for (int i = 0; i < n; i++) {
        printf("Frame no: %d, Fingerprint: %s\n", arr[i].frameno, arr[i].fingerprint);
    }
    
    return 0;
}

