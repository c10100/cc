#include <stdio.h>

// 定义一个通用的交换函数，可以交换任意类型的数据
// void *a 和 void *b 是交换的两个数据的指针 至于数据是什么类型 只需要知道它们的大小
void swap(void *a, void *b, size_t size)
{
    // 把两个指针强制转换为char类型指针，逐个字节交换数据
    for (size_t i = 0; i < size; i++)
    {
        // 交换两个char类型数据的值（不管原来的数据是什么类型 逐个字节交换）
        char temp = *((char *)a + i);
        *((char *)a + i) = *((char *)b + i);
        *((char *)b + i) = temp;
    }
}

int main()
{
    int a = 5;
    int b = 10;
    printf("main函数交换前 a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("main函数交换后 a = %d, b = %d\n", a, b);

    char x = 1;
    char y = 2;
    printf("main函数交换前 x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(char));
    printf("main函数交换后 x = %d, y = %d\n", x, y);
}