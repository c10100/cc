#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
qsort (利用快速排序法排列数组)
定义函数 void qsort(void * base, size_t nmemb, size_t size, int (* compar) (const void*, const void *));

void * base // 通用类型的指针，指向要排序的数组的起始地址
size_t nmemb // 要排序的元素个数
size_t size // 每个元素的大小，以字节为单位
int (* compar) (void*, void *)
*/

int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; // 比较函数，返回两个元素的差值
    // a和b是两个元素的指针，通过强制类型转换为int类型的指针，然后解引用，再进行比较
}

int compar2(const void *a, const void *b)
{
    // return *(char *)a - *(char *)b; // 比较函数，返回两个元素的差值  升序
    // return *(char *)b - *(char *)a; // 比较函数，返回两个元素的差值   降序
    return rand() % 3 - 1; // [-1 0 1]  随机排序
}

int main()
{

    srand(time(NULL)); // 设置随机数种子，用于生成随机数

    int arr[] = {5, 2, 9, 1, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, len, sizeof(int), compar); // 调用qsort函数进行排序

    printf("排序后的数组为：");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ==================================
    char nums[] = {3, 102, 5, -2, 98, 52, 18};
    int num_len = sizeof(nums) / sizeof(nums[0]);
    printf("排序前的数组为：");
    for (int i = 0; i < num_len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    qsort(nums, num_len, sizeof(char), compar2); // 调用qsort函数进行排序

    printf("排序后的数组为：");
    for (int i = 0; i < num_len; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}