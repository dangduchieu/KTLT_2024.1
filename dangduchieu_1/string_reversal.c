#include <stdio.h>
#include <string.h> // thư viện này chứa các hàm xử lý chuỗi

void reverseString(char *str) // sử dụng con trỏ để lưu trực tiếp các giá trị thay đổi vào ô nhớ
{
    int length = strlen(str);
    int start = 0; int end = length -1; // hai bien danh dau vi tri dau va cuoi
    char temp; // biến tạm để hoán đổi vị trí

    while( start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // hàm nhập chuỗi từ bàn phím, str: chuỗi dùng để lưu ký tự vào, stdin: đầu vào chuẩn là bàn phím

    str[strcspn(str, "\n")] = '\0';
    // dùng để xoá kí tự "\n", còn hàm strcspn(str, "\n") : dùng để tìm vị trí ký tự đó

    reverseString(str);
    printf("Reversed string is: %s\n", str);

    return 0;

}

