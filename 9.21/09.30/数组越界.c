#include <stdio.h>

int main()
{

    int nums[] = {11, 22, 33}; // 数组定义的时候如果没有写个数 根据初始化列表自动匹配

    printf("sizeof(nums)=%d\n", sizeof(nums));

    printf("%d\n", nums[0]);
    printf("%d\n", nums[1]);
    printf("%d\n", nums[2]);
    printf("%d\n", nums[3]); // 越界读取随机值（没意义）  越界修改危险可能导致栈崩溃
    printf("%d\n", nums[4]);

    printf("============\n");

    // 数组的遍历访问（读取）
    int length = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < length; i++)
    {
        printf("i=%d  nums[i]=%d\n", i, nums[i]);
    }

    int arr[5] = {0}; // 把整个数组所有元素都初始化为0
    return 0;
}
