#include <stdio.h>
// khi khong su dung typedef

//int main(){
 //   int x = 20;
   // int *ptr = &x; // con tro kieu int
    //printf("Dia chi cua x la: %d\n gia tri cua x la: %d\n", ptr, *ptr);
    //return 0;
//}

// khi su dung typedef
#include <stdio.h>

typedef int* IntPtr;

int main() {
    int x = 10;
    IntPtr p1 = &x, p2 = &x; // Không cần dùng dấu * nhiều lần
    printf("Giá trị của x: %d\n", *p1);
    return 0;
}
