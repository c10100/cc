#include <stdio.h>

int main()
{
    int buf[3] = {10, 20, 30};

    int *pbuf = buf; // 一维数组的指针  数组指针
    printf("%p %p\n", pbuf, pbuf + 1);

    int seat[3][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}};
    int (*pseat)[5] = seat; // 二维数组的指针 数组指针
    printf("%p %p\n", pseat, pseat + 1);

    int a = 10;
    int b = 20;
    int c = 30;
    int *arr[3] = {&a, &b, &c}; // 指针元素组成的数组  指针数组
    printf("%p %p\n", arr, arr + 1);

    int **parr = arr; // parr是 指针元素组成的 数组的 指针     指针数组指针
    printf("%p %p\n", parr, parr + 1);
}