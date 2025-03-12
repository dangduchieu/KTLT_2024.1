#include <stdio.h>

void filterEvenNumbers(int arr[], int size, int evenArr[], int *evenSize)
{
    *evenSize = 0; //khoi tao so luong phan tu chan ve 0
    for( int i=0; i < size; i++)
    {
        if( arr[i] % 2 == 0)
        {
            evenArr[*evenSize] = arr[i]; // lưu số chẵn vào mảng mới
            (*evenSize)++;
        }

    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n); // nhap so phan tu cua mang

    int arr[n], evenArr[n], evenSize;
    // nhap cac phan tu cua mang
    printf( " Enter %d numbers: ", n);
    for(int i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    filterEvenNumbers(arr, n, evenArr, &evenSize);

    printf ("Even numbers: ");
    for (int i =0; i < evenSize; i++){
        printf("%d ", evenArr[i]);
    }

    return 0;
}