#include <stdio.h>

int main()
{
    int arr1[5] = {11, 12, 13, 14, 15};
    int arr2[5] = {21, 22, 23, 24, 25};
    int arr3[5] = {31, 32, 33, 34, 35};

    printf("arr1=%p\n", arr1); // arr1是11的地址 int*

    // arr是一个有三个元素的数组 元素类型是int*   指针数组
    int *arr[3] = {arr1, arr2, arr3};
    printf("%d\n", sizeof(arr));

    printf("%p %p\n", arr1, arr1 + 1);
    printf("%p %p\n", arr, arr + 1);     // 8 arr是 arr数组的首元素的地址  首元素的值是arr1的地址
    printf("%p %p\n", *arr, *arr + 1);   // 4
    printf("%d %d\n", **arr, **arr + 1); // 11 12

    printf("%p %p\n", arr[0], arr[0] + 1);
    printf("%p %p\n", *arr, *arr + 1);

    printf("%d\n", *(arr[1] + 3));
    printf("%d\n", arr[1][3]);

    int seat[3][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}};

    printf("sizeof(seat)=%d\n", sizeof(seat));
    printf("%d\n", seat[1][3]); // *(seat[1] + 3)

    printf("%p %p\n", seat, seat + 1);
}