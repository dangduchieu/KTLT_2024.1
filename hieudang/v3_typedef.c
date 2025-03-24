// sử dụng typedef với struct

#include <stdio.h>

typedef struct{
    char name[50];
    int age;
} person;

int main(){
    person p1 = { "dang duc hieu", 20};
    printf("Name: %s, Age: %d\n", p1.name, p1.age );
    return 0;
}