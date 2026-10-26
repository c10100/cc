#include <stdio.h>
int main()
{
    int arr[6] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    // int mid;
    int left = 0;
    int count = 0;
    int kt = -1, mw = -1;
    int right = (sizeof(arr) / sizeof(arr[0]))-1;
    // printf("%d", right);
    while (left < sizeof(arr) / sizeof(arr[0]))
    {
        if (target > arr[left])
        {
            left++;
        }
        else if (target == arr[left])
        {
            kt = arr[left];
            // printf("找到了起始下标为%d\n", left);
            break;
        }
        else
        {
            break;
        }
    }
    while (right > 0)
    {
        if (target < arr[right])
        {
            right--;
        }
        else if (target == arr[right])
        {
            mw = arr[right];
            // printf("找到了起始下标为%d\n", right);
            break;
        }
        else
        {
            break;
        }
    }
    if (kt == -1 && mw == -1)
    {
        printf("找不到[%d, %d]\n", kt, mw);
    }
    else
    {
        printf("[%d, %d]", left, right);
    }
    return 0;
}