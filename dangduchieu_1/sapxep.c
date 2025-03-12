#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi arr[j] và arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 8, 1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Mảng ban đầu: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Mảng sau khi sắp xếp: ");
    printArray(arr, n);
    
    return 0;
}