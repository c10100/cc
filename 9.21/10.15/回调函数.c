#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compar(const void *a, const void *b)
{
    // return *(int *)b - *(int *)a;//升序排列
    return rand()%3-1;//随机排序
}
int main()
{
    int str[10] = {-1, 3, 4, 76, 92, 27, 2, 9, 0, 37};
    int len = sizeof(str) / sizeof(str[0]);
    qsort(str, len, sizeof(int), compar);
    printf("排列后的数组为");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", str[i]);
    }
        //------------//随机生成数字
    // srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // { 
    //     // printf(" %d ", 1 + (int) (100.0 * rand() / (RAND_MAX + 1.0)));
    //     printf(" %d ", rand()%100+1);
    // }

    return 0;
}