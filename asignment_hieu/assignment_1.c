#include <stdio.h>
#include <string.h>

void reverseString(char *a) //void reverseString(char str[]) { // Vẫn tương đương với char *str
{
    int length = strlen(a);
    int start = 0; int end = length -1;
    char box;

    while( start < end)
    {
        box = a[start];
        a[start]= a[end];
        a[end]= box;
        start++;
        end--; 
    }
}
int main()
{
    char a[100];
    printf("Enter a string: ");
    fgets( a, sizeof(a), stdin);

    a[strcspn(a, "\n")]= '\0';

    reverseString(a);
    printf("Reversed string is: %s ", a);
    return 0;
}