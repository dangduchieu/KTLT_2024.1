#include <stdio.h>

int main()
{
    int n;
example:
    printf("Nhap n: ");// stament 1
    scanf("%d", &n);
    if (n < 0) {
        printf("Nhap lai n\n");// stament 2
        goto example;
    }
    printf("Correct");// stament 3
    return 0;
}