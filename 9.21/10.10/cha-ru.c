#include <stdio.h>
int main()
{
    int arr[5] = {1, 8, 1, 5, 9};
    // int a = 2;
    for (int j = 1; j < 5; j++)
    {
        int a = j;
        int base = arr[a];
        while (a >= 0)
        {
            if (base < arr[a - 1])
            {
                arr[a] = arr[a - 1];
                arr[a - 1] = base;
            }
            
            a--;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

// #include <stdio.h>

// int main(void)
// {
//     int arr[5] = {9, 8, 1, 5, 3};
//     const int n = 5;

//     // 插入排序
//     for (int j = 1; j < n; j++)
//     {
//         int key = arr[j];
//         int i = j - 1;

//         // 将比 key 大的元素向后移动
//         while (i >= 0 && arr[i] > key)
//         {
//             arr[i + 1] = arr[i];
//             i--;
//         }
//         arr[i + 1] = key;
//     }

//     // 输出排序结果
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\n", arr[i]);
//     }

//     return 0;
// }