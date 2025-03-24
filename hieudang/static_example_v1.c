#include <stdio.h>

void add()
{
static int x = 0;
    x++;
    printf("%d\n", x);
}

int main()
{
    for(int i=0; i<5; i++)
    {
        add();
    }
    return 0;
}