#include <stdio.h>

int compar(int a, int b)
{
    // return a - b; // 升序排列
    return b - a; // 降序排列
}

void insertSort(int *arr, int length, int (*compar)(int, int))
{

    // i是已排序区间的最后一个下标
    for (int i = 0; i < length - 1; i++)
    {
        int base = arr[i + 1];
        int j = i;

        while (j >= 0)
        {
            if (compar(arr[j], base) > 0) // arr[j] > base
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                arr[j + 1] = base;
                break;
            }
        }

        arr[j + 1] = base;
    }
}

int main()
{

    int nums2[6] = {4, 1, 3, 1, 5, 2};
    int nums2_length = sizeof(nums2) / sizeof(nums2[0]);

    // char nums2[7] = {11, 2, 35, 4, 9, 2, 1};
    // char nums2_length = sizeof(nums2) / sizeof(nums2[0]);

    insertSort(nums2, nums2_length, compar);

    // ---------------
    for (int i = 0; i < nums2_length; i++)
    {
        printf("%d ", nums2[i]);
    }
}