#include <stdio.h>
// tạo hàm insao với tham số truyền vào là n, in ra n sao
// sử dụng goto để thực hiện vòng lặp
// goto trong hàm void với mục đích lặp đi lặp lại n lần 'printf("*");'
// goto trong main để truyền vào hàm insao với tham số đầu vào mới.
void insao(int n){
    int x=1;
    hieu:
    if(x<n+1){
        printf("*");
        x++;
        goto hieu;

    }
}

int main(){
    int m=1;
example:
    if((m>0)&&(m<1001))
    {
        printf("\nDong %d: ", m);
        insao(m);
        m++;
        goto example;
    }
    return 0;

}


