// khai bao enum voi gia tri tuy chinh

#include <stdio.h>

enum status {
    success = 1,
    failure = -1,
    pending = 0,
};

int main(){
    enum status myStatus = success;
    printf("Trang thai hien tai: %d\n", myStatus);
    return 0;
}