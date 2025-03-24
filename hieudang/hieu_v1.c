// định nghĩa enum với typedef

#include <stdio.h>

// dinh nghia

typedef enum {
    MONDAY = 2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} days;

int main(){
    days hieu = MONDAY;
    printf("hom nay la thu %d\n", hieu);
    return 0;
}