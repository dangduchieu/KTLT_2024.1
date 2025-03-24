//duyen qua cac gia tri trong enum

#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

int main()
{
    for (enum day d = sun; d <=sat; d++){
        printf("%d\n", d);
    }
    return 0;
}