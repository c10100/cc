#include <stdio.h>

int main()
{
    char str1[] = "hello";        // 申请一个字符数组，使用字符串常量初始化
    printf("%d\n", sizeof(str1)); // str1是一个6字节的char数组 每个字节存储 h e l l o \0

    char *str2 = "hello";         // 申请一个字符指针，指向字符串常量
    printf("%d\n", sizeof(str2)); // str2 用8个字节存储一个地址

    str1[1] = 'E';
    printf("%s\n", str1);

    printf("%c\n", *(str2 + 1));
    printf("%c\n", str2[1]);
    // str2[1] = 'E'; //  ❌ 修改字符串常量 会段错误 Segmentation fault (core dumped)

    str2 = "world"; // 修改栈内存中 变量的值 ✔

    printf("%s\n", str2);
}