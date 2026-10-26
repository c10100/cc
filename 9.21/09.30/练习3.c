#include <stdio.h>

int main()
{
    int nums[10] = {0};
    int count = 0;
    while (1)
    {
        int res = scanf("%d", &nums[count++]);
        if (res != 1)
        {
            printf("获取失败\n");
            return -1;
        }

        if (getchar() == '\n')
        {
            break;
        }
    }

    printf("============\n");
    for (int i = 0; i < count; i++)
    {
        printf("i=%d  nums[i]=%d \n", i, nums[i]);
    }
    printf("============\n");

    // int nums[4] = {10, 40, 23, 13};
    int max = nums[0], min = nums[0];
    for (int i = 0; i < count; i++)
    {
        // printf("%d\n", nums[i]);
        if (nums[i] < min)
        {
            min = nums[i];
        }

        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    printf("min=%d max=%d\n", min, max);

    return 0;
}
