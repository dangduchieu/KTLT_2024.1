// write a program that takes a list of numbers and returns a new list contaning only the even numbers.

#include <stdio.h>
// truyền địa chỉ của evenSize vào, sau đó thay đổi giá trị địa chỉ ô nhớ đó
void filterEvenNumbers(int arr[], int size, int evenArr[], int *evenSize) {
    *evenSize = 0; // Khởi tạo số lượng phần tử chẵn về 0
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[*evenSize] = arr[i]; // Lưu số chẵn vào mảng mới
            (*evenSize)++; // Tăng biến đếm số lượng số chẵn
        }
    }
}

int main() {
    int n;
    
    // Nhập số phần tử của mảng
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n], evenArr[n], evenSize;
    
    // Nhập mảng từ bàn phím
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Gọi hàm lọc số chẵn
    filterEvenNumbers(arr, n, evenArr, &evenSize); // truyền địa chỉ của evenSize vào hàm 
    // evenArr là mảng, tức là bản chất nó là địa chỉ, evenSize lưu giá trị chứ không phải địa chỉ nên cần & để truyền địa chỉ vào hàm.

    // In ra danh sách số chẵn
    printf("Even numbers: ");
    for (int i = 0; i < evenSize; i++) {
        printf("%d ", evenArr[i]);
    }
    
    return 0;
}

