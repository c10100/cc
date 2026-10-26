#include <stdio.h>
int main()
{
    int arr[10] = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    int target = 1;
    int mid;
    int left = 0;
    int count = 0;
    int flag = 0;
    int right = sizeof(arr) / sizeof(arr[0]);
    // printf("%d", right);
    while (right >= left)
    {
        count++;
        mid = (left + (right - left) / 2);
        if (target > arr[mid])
        {
            left = mid + 1;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else if(target == arr[mid])
        {
            flag = 1;
            printf("找到了下标为%d\n", mid);
            break;
        }
    }
    if(flag == 0)
    {
        printf("找不到\n");
    }
    printf("循环次数%d", count);
    return 0;
}