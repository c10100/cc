#include <stdio.h>

int main()
{

    char strs1[3][10] = {"hello", "world", "welcome"};
    // 申请3*10个字符的内存空间
    // 三个元素类型是 char[10] 使用字符串常量初始化 三个元素

    char *strs2[3] = {"hello", "world", "welcome"};
    // 申请3*8 3个指针的内存空间，每个指针指向一个字符串常量
    // 三个元素类型是 char* 保存了 三个字符串常量的地址

    printf("%s\n", strs1[0]);
    printf("%s\n", strs2[0]);

    printf("%c\n", strs1[0][1]);
    printf("%c\n", strs2[0][1]);

    strs1[0][1] = 'E';
    printf("%s\n", strs1[0]);

    // strs2[0][1] = 'E'; // 错误，因为 strs2[0] 是指向字符串常量的指针，不能修改字符串常量的内容
    // printf("%s\n", strs2[0]);

    printf("%p %p\n", strs2, strs2 + 1);
    printf("%p %p\n", strs2[0], strs2[0] + 1);

    printf("%s %s\n", strs2[0], strs2[0] + 1);
    printf("%c %c\n", strs2[0][0], strs2[0][1]); // strs2[0][0] == *(strs2[0] + 0)

    printf("end\n");
}
