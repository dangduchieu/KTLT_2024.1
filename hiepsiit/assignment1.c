#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i=1; i<n+1; i++)
    {
        sum += i;
    }
    printf("Tong cua day: %d\n", sum);
    return 0;
}