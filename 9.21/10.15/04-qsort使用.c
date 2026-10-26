#include <stdio.h>
#include <stdlib.h>
/*
qsort (利用快速排序法排列数组)
定义函数 void qsort(void * base, size_t nmemb, size_t size, int (* compar) (const void*, const void *));

void * base // 通用类型的指针，指向要排序的数组的起始地址
size_t nmemb // 要排序的元素个数
size_t size // 每个元素的大小，以字节为单位
int (* compar) (const void*, const void *)
*/

int compar1(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int compar2(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{

    int arr[6] = {5, 2, 9, 1, 5, 6};
    qsort(arr, 6, sizeof(int), compar2);

    printf("排序后的数组为：");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}