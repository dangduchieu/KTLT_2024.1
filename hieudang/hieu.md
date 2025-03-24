### Đặng Đức Hiếu(20232071)
# Những kiến thức mới đã học được sau buổi 1

## Cách tính kích thước kiểu struct:
1. Bắt đầu từ byte 0 và duyệt từng member theo thứ tự khai báo.
2. Nếu địa chỉ hiện tại không chia hết cho yêu cầu căn chỉnh của member tiếp theo, thêm padding cho chúng đến địa chỉ đúng.
3. Sau khi duyệt hết, đảm bảo kích thước tổng của struct là bội số của member lớn nhất.

Ví dụ:
```c
struct example{
    char a; //1 byte
    int b; //4 byte( có thể là 2 byte tuỳ máy)
    double c; //8 byte
    short d; //2 byte
}
```
- Kích cỡ của struct này là 24 byte tương đương 3 thanh 8 byte.

- Giải thích: c là member có kích thước lớn nhất 8 byte nên mỗi thanh ghi sẽ có kích thước là 8 byte, a được khai báo đầu tiên nên sẽ ở vị trí byte 0 nhưng đến byte 1 không thoả mãn yêu cầu căn chỉnh của b nên sẽ để trống 3 byte và bắt đầu từ byte 4. Làm tương tự đến d ( ở thanh số 3) sẽ nằm ở byte 0 và 1 và để trống 6 byte còn lại.

- Có thế tối ưu cách căn chỉnh để giảm padding bằng cách khai báo các member theo thứ tự giảm dần về kích thước.

Ví dụ:
```c
struct example{
    double c; //8 byte
    int b; //4 byte
    short d; //2 byte
    char a; //1 byte
}
```
## Buil process overveiw

#### 1. Preprocessing (Tiền xử lý)

- Công cụ: cpp ( C preprocessor)
- Xử lý các dòng lệnh `#include`, `#define`, macro, chỉ thị tiền xử lý. Các câu lệnh như `#include <stdio.h>` sẽ được thay thế bằng nội dung thực tế của tệp header.

Ví dụ: 
```C
#include <stdio.h>
int main() 
{
    printf("Hello, World!");
    return 0;
}
```
Bộ tiền xử lý sẽ mở rộng mã nguồn như sau:
```c
// Nội dung của stdio.h được chèn vào đây
int printf(const char *format, ...);

int main() {
    printf("Hello, World!");  // Hàm printf đã được khai báo
    return 0;
}
```
**⇒ Nếu không có Header files chương trình sẽ không hiểu `printf()`là gì và trình biên dịch sẽ báo lỗi.**
- Loại bỏ comment và thay thế macro trước khi biên dịch.






#### 2. Compilation (Biên dịch)

- Công cụ: gcc hoặc clang.
- Chuyển mã nguồn thành Assembly(.s).
- Kiểm tra cú pháp và báo lỗi nếu có.

Ví dụ mã Assembly:
```c
    .section .rodata
.LC0:
    .string "Pi = %f\n"
main:
    pushq   %rbp
    movq    %rsp, %rbp
    movsd   .LC0(%rip), %xmm0
    call    printf
    popq    %rbp
    ret

```
#### 3. Assembling (Dịch mã máy)

Chuyển mã Assembly(.s) thành mã máy(.o) để CPU có thể hiểu nhưng vẫn chưa chạy được vì thiếu bước linking.


#### 4. Linking (Liên kết)

- Công cụ: ld (linker).
- Gộp nhiều file object(.o) lại .
- Liên kết với library files(libc, libm,...), các library files chứa các định nghĩa thực tế của các hàm đã khai báo trong header files ⇒ Nếu không có Library files chương trình sẽ khong biết `printf()` thực sự làm gì và sẽ không thể tạo file(.exe).
- Tạo file thực thi(.out hoặc .exe).

## Memory layout
#### 1. Text segment
Text segment là vùng bộ nhớ chứa mã lệnh thực thi của chương trình.
- Chỉ chứa mã máy, không có biến cục bộ hoặc cấp phát động.
- Chỉ đọc, không thế ghi vào( read-only), không thể thay đổi nội dung trong khi chạy.
- Các tiến trình có Stack, Heap, Data segment riêng nhưng có thể cùng dùng chung text segment.

#### 2. Data segment
Chứa biến global và static đã khởi tạo( với giá trị khác 0) trước khi chương trình chạy.


Ví dụ:
```c
int global_var = 10;   // Thuộc Data Segment
static int static_var = 20;  // Cũng thuộc Data Segment

```
#### 3. BSS segment

Chứa biến global và static chưa khởi tạo hoặc khởi tạo với giá trị bằng 0, các biến trong BSS được khởi tạo mặc định là 0.

#### 4. Heap
Dùng để cấp phát bộ nhớ động khi chạy chương trình(malloc, calloc, realloc).
Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 5);  // Cấp phát 5 số nguyên trong Heap
    ptr[0] = 42;
    free(ptr);  // Giải phóng bộ nhớ
    return 0;
}
```
#### 5. Stack
Stack chứa biến cục bộ, tham số hàm, địa chỉ trả về.
- Tăng giảm tự động khi gọi hàm push/pop.
- LIFO( Last In, First Out): Vào sau, ra trước

Dữ liệu được đẩy vào Stack, phần tử nào được đẩy vào sau cùng sẽ được lấy ra đầu tiên.


Ví dụ:
```c
#include <stdio.h>

int main() {
    int stack[3]; // Stack có 3 phần tử
    stack[0] = 10;  // Push 10
    stack[1] = 20;  // Push 20
    stack[2] = 30;  // Push 30

    printf("%d\n", stack[2]); // Pop: Lấy 30 trước
    printf("%d\n", stack[1]); // Pop: Lấy 20
    printf("%d\n", stack[0]); // Pop: Lấy 10
    return 0;
}

```
- Nếu dùng quá nhiều sẽ gây Stack Overflow

Stack Overflow xảy ra khi vùng nhớ Stack bị đầy do quá nhiều dữ liệu được đẩy vào mà không có đủ không gian trống.

## Giữa macro và hàm thì cái nào nhanh hơn ?
**Macro** là đoạn mã được thay thế trực tiếp vào chương trình trước khi biên dịch. Được định nghĩa bằng `#define` và xử lý bới Preprocessor(Bộ tiền xử lý) và không có lời gọi hàm( chỉ thay thế văn bản) giúp tăng tốc độ thực thi.

Ưu điểm và nhược điểm của macro:
- Ưu điểm: Nhanh hơn hàm vì không mất phí gọi hàm, dễ dùng cho các phép tính đơn giản.
- Nhược điểm:
    + Không kiểm tra kiểu dữ liệu, có thể gây lỗi
    + Code dài hơn nếu gọi nhiều lần, vì mỗi lần sử dụng sẽ tạo một bản sao.
    + Khó debug vì không thế đặt breakpoint

**Hàm trong C** là một khối mã thực thi có thể được gọi nhiều lần. Khi gọi hàm CPU đẩy tham số vào Stack, lưu địa chỉ trả về rồi thực hiện câu lệnh trong hàm.
- Ưu điểm:
    + Dễ đọc, dễ debug, có thể đặt breakpoint.
    + Kiểm tra dữ liệu chặt chẽ.
    + Giảm kích thước mã nguồn, vì chỉ có một bản định nghĩa hàm.
- Nhược điểm: chậm hơn macro vì phải gọi hàm và tốn tài nguyên CPU hơn.



## Conditional compilation
Conditional compilation( Biên dịch có điều kiện) là cơ chế giúp bộ tiền xử lý( Preprocessor) của C kiểm tra và xử lý mã nguồn dựa trên điều kiện nhất định, giúp kiểm soát quá trình biên dịch mà không cần sửa mã nguồn.

#### `#ifdef` - Kiểm tra macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì đoạn code bên trong sẽ được định nghĩa.

#### `#endif` - Dùng để kết thúc khối `#ifdef`, `#ifndef`, `#if`.

Ví dụ:
```c
#include <stdio.h>

#define DEBUG // Định nghĩa macro DEBUG

int main() {
#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif
    printf("Program running...\n");
    return 0;
}

```
#### `#ifndef` - Kiểm tra macro chưa được định nghĩa, nếu macro chưa được định nghĩa thì đoạn code bên trong sẽ được định nghĩa.

Ví dụ:
```c
#include <stdio.h>

#ifndef RELEASE
#define DEBUG // Nếu không có RELEASE, bật DEBUG
#endif

int main() {
#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif
    return 0;
}

```
#### `#else` - Thay thế khi điều kiện không đúng

Ví dụ:
```c
#include <stdio.h>

// #define DEBUG // Nếu bỏ dòng này, chương trình chạy khối #else

int main() {
#ifdef DEBUG
    printf("Debugging mode enabled.\n");
#else
    printf("Normal mode enabled.\n");
#endif
    return 0;
}

```

## Characteristics of Variables
#### Các key word cho biến
#### `Static`- Kiểm soát thời gian timelife và scope của một biến.
Ví dụ khi không sử dụng static
```c
#include <stdio.h>

void add()
{
    int x = 0;
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
```
Kết quả:
```
PS C:\KTLT_C\hieudang> .\static_example_v1.exe
1
1
1
1
1
```
Ví dụ khi có static:
```c
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
```
Kết quả:
```
PS C:\KTLT_C\hieudang> .\static_example_v1.exe
1
2
3
4
5
```
#### `Extern` - Mở rộng vùng hoạt động có thể truy cập biến ở các file khác nhau bằng việc liên kết các file.o

Ví dụ áp dụng `extern` với hàm.

`file1.c` (Định nghĩa hàm)
```c
#include <stdio.h>

// Định nghĩa hàm
void sayHello() {
    printf("Hello from file1.c!\n");
}

```
`file2.c` (Gọi hàm với `extern`)
```c
#include <stdio.h>

// Khai báo extern (biến đã được định nghĩa ở file1.c)
extern int globalVar;

void modifyVar() {
    globalVar += 5; // Thay đổi giá trị của biến toàn cục
}

int main() {
    modifyVar();
    printf("Modified Global Variable: %d\n", globalVar);
    return 0;
}


```
***Điều kiện là hai file này phải ở chung một thư mục.***

#### `Register` - Lưu ở thanh ghi CPU thanh vì memory làm truy cập nhanh hơn nhưng khó debug và không lấy được địa chỉ nênn ít sử dụng 

Ví dụ:
```c
#include <stdio.h>

int main() {
    register int i; // Yêu cầu lưu biến i vào thanh ghi CPU

    for (i = 0; i < 10; i++) {
        printf("%d ", i);
    }

    return 0;
}

```
#### `Volatile` - load lại vùng nhớ của một biến có thể thay đổi giá trị sử dụng trong trong xử lý ISR hoặc multi threads.

Ví dụ mô phỏng thanh ghi trạng thái của thiết bị ngoại vi:
```c
#include <stdio.h>

volatile int statusRegister; // Thanh ghi trạng thái có thể thay đổi bất cứ lúc nào

void hardwareInterrupt() { 
    statusRegister = 1; // Giả lập một sự kiện phần cứng thay đổi giá trị
}

int main() {
    printf("Đang chờ thiết bị...\n");

    while (statusRegister == 0) {
        // Vòng lặp đợi thiết bị thay đổi trạng thái
    }

    printf("Thiết bị đã sẵn sàng!\n");
    return 0;
}

```

## Data structure
#### `struct`
- struct là một kiểu dữ liệu do người dùng định nghĩa, giúp nhóm nhiều kiểu dữ liệu lại trong một đối tượng.
- mỗi member của một struct có một vùng nhớ riêng.

Ví dụ:
```c
#include <stdio.h>

// Định nghĩa struct
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student s1 = {"Alice", 20, 3.8};

    printf("Tên: %s\n", s1.name);
    printf("Tuổi: %d\n", s1.age);
    printf("GPA: %.2f\n", s1.gpa);

    return 0;
}

```
#### `union`
- `union` là kiểu dữ liệu người dùng tự định nghĩa, giống `struct` nhưng chỉ có một vùng nhớ dùng chung.
- Tất cả member dùng chung một vùng nhớ, kích thước của `union` bằng kích thước của member lớn nhất.


Ví dụ:
```c
#include <stdio.h>

// Định nghĩa union
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("i = %d\n", data.i);

    data.f = 220.5;
    printf("f = %.2f\n", data.f);

    strcpy(data.str, "Hello");
    printf("str = %s\n", data.str);

    return 0;
}

```
#### `enum`

- `enum` là kiểu dữ liệu trong C, dùng để định nghĩa danh sách các hằng số nguyên có tên.
- Các giá trị mặc định là 0 và tăng dần.


Ví dụ khi khai báo enum với một giá trị tuỳ chỉnh
```c
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

// kết quả là: 
Trang thai hien tai: 1
```