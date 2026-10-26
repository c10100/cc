#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int capacity = 20;              // 初始容量
    char *a = (char *)malloc(capacity * sizeof(char));
    if (a == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    while (1)
    {
        if (scanf("%19s", a) != 1)  // 先按原逻辑读入
            break;

        if (a[0] == 'x')            // 以 x 开头就退出
            break;

        // 遍历实际字符（到 '\0' 为止），做替换
        for (int i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == 'a' || a[i] == 'A')
                a[i] = '*';
            else if (a[i] == 'b' || a[i] == 'B')
                a[i] = '#';
        }

        printf("%s\n", a);
    }

    free(a);                        // 释放堆空间
    return 0;
}