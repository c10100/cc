#include <stdio.h>

int main()
{
    int nums[5] = {11, 22, 33, 44, 55};
    printf("%p %p\n", nums, nums + 1); // 1.定义声明 2.sizeof(nums) 3.&nums  之外都代表数组的首元素地址

    int *p = nums;
    printf("%p %p\n", p, p + 1);
    // nums 或者p 叫做数组的指针  数组指针(首地址)
    return 0;
}
