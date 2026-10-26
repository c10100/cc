#include <stdio.h>
#include <stdlib.h>

// void*  malloc(size_t size); // 申请?字节的堆内存，返回指向该内存区域的基地址
// 返回的void* 指针，没有类型的指针（任意类型的指针）

int main()
{
    char *p1 = (char *)0x100;
    printf("p1 = %p %p\n", p1, p1 + 1);

    int *p2 = (int *)0x100;
    printf("p2 = %p %p\n", p2, p2 + 1);

    int *p3 = (int *)malloc(20); // 申请到的空间不会置0 随机值
    // 申请20个字节的堆内存，把返回的地址强制转化为 int*
    printf("p3 = %p %p\n", p3, p3 + 1);

    p3[0] = 11;
    p3[1] = 22;
    p3[2] = 33;
    p3[3] = 44;
    p3[4] = 55;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p3[i]);
    }
    printf("\n");

    // 3行5列的二维数组
    int (*p4)[5] = malloc(60);
    printf("p4 = %p %p\n", p4, p4 + 1);

    p4[0][0] = 11;
    p4[0][1] = 12;
    p4[0][2] = 13;
    p4[0][3] = 14;
    p4[0][4] = 15;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", p4[i][j]);
        }
    }
}
