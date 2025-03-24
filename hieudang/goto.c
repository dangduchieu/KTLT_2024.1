#include <stdio.h>

int main(){

    int x=1;
example:
    if((x>0)&&(x<1001)) // điều kiện để có thể in ra 1 đến 1000 
    {
        printf("%d\n", x);
        x++;// x có giá trị mới, goto example để in ra giá trị mới của x
        goto example;
    }

    return 0;
}