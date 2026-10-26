#include <stdio.h>

int main()
{
    int seat[3][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}};

    printf("%d\n", sizeof(seat));

    printf("%p %p\n", &seat[0][0], &seat[0][0] + 1); // 11的地址
    printf("%p %p\n", seat, seat + 1);               // seat 退化为首元素（{11, 12, 13, 14, 15}）的地址
    printf("%p %p\n", &seat, &seat + 1);             // &seat 整个数组的地址

    printf("=====%p %p %d\n", seat[0], seat[0] + 1, *(seat[0] + 1));
    // seat[0] 代表seat数组的第0行的值 {11, 12, 13, 14, 15}
    // seat[0] + 1  数组+1  数组{11, 12, 13, 14, 15} 退化为11的地址
    // nums + i = &nums[i]  *(nums + i) = nums[i]
    // seat[0] + 1 === &seat[0][1]

    // printf("", seat + 1); // seat是{11, 12, 13, 14, 15}的地址  seat + 1是{21, 22, 23, 24, 25}的地址
    // printf("", *(seat + 1)); // *(seat + 1) {21, 22, 23, 24, 25}的值
    // printf("", *(seat + 1) + 2); //  {21, 22, 23, 24, 25}  + 2 数组会退化为这个首元素的地址 21的地址   23的地址
    printf("%d\n", *(*(seat + 1) + 2)); // *(23的地址)
                                        // *(seat + 1) == seat[1]
                                        // *(seat[1] + 2)) == seat[1][2]

    // *p = seat    int[5]  *p = seat     int (*p)[5] = seat
    int (*p)[5] = seat; // p代表{11, 12, 13, 14, 15}的地址
    // 二维数组的指针
    // 先读(*p) p是一个指针  再读[5] 指向的目标元素的类型是有5个元素的数组 元素类型是int

    // int *arr[4] 先读arr[4]  arr是一个数组 有4个元素  元素类型 int *
    return 0;
}
