#include <stdio.h>

int main()
{
    // 字符数组 由字符元素组成的数组
    // 指针数组 由指针元素组成的数组
    int a = 10, b = 20, c = 30, d = 40;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;

    int nums[4] = {a, b, c, d};
    printf("sizeof(nums)=%llu\n", sizeof(nums));

    // 数组元素的类型 数组名[元素个数] = 初始化列表
    int *arr[4] = {pa, pb, pc, pd};
    printf("sizeof(arr)=%llu\n", sizeof(arr));

    printf("arr[0]=%p\n", arr[0]);
    printf("*arr[0]=%d\n", *arr[0]);

    return 0;
}
