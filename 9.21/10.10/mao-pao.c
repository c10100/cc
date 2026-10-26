#include <stdio.h>
int main()
{
    int arr[5] = {8, 7, 1, 3, 2};
    for (int i = 0; i < 4; i++)//外层循环n-1
    {
        for (int j = 0; j < 4-i; j++)//内层做交换
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}