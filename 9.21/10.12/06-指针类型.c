#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char a = 10;
    char *pa = &a;

    // 地址偏移量 =  n * sizeof(指针指向的目标元素的大小)
    printf("%p %p\n", pa, pa + 1);

    int b = 10;
    int *pb = &b;
    printf("%p %p\n", pb, pb + 1);

    // char *str1[3];
    // strcpy(str1[0], "zhang3");

    char str2[3][10];
    strcpy(str2[0], "zhang3");

    printf("end\n");
}