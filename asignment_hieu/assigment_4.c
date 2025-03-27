#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Hàm kiểm tra hai chuỗi có phải là anagram không
bool areAnagrams(char *str1, char *str2) {
    int count[256] = {0};

    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    for (int i = 0; str1[i] && str2[i]; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    // Kiểm tra anagram
    char str1[] = "listen";
    char str2[] = "silent";
    printf("Are '%s' and '%s' anagrams? %s\n", str1, str2, areAnagrams(str1, str2) ? "Yes" : "No");
    return 0;
}
