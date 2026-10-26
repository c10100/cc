//8、拓展 一维数组 转 二维数组 二维数组 转一维数组（堆内存
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// void main()
// {
//     char *arr1 = (char*)malloc(10*sizeof(char));
//     strcpy(arr1, "helloworld");
//     
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char arr1[15] = {11, 12, 13, 14, 15, 21, 22, 23, 24, 25, 31, 32, 33, 34, 35};
    char arr2[3][5] = {11, 12, 13, 14, 15, 21, 22, 23, 24, 25, 31, 32, 33, 34, 35};

    printf("%d\n", arr1[14]);
    printf("%d\n", arr2[2][4]);
    printf("%d\n", *(arr1 + 14));
    printf("%d\n", *(*(arr2 + 2) + 4));

    char *p1 = (char *)arr2; // 二维转一维
    printf("%d\n", *(p1 + 14));

    char (*p2)[5] = (char (*)[5])arr1; // 一维转二维
    printf("%d\n", p2[2][4]);

    return 0;
}