// 编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入”a b”，输出”ab”）
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *arr = (char *)malloc(1000 * sizeof(char));
    if (arr == NULL)
    {
        printf("内存分配失败");
        return 1;
    }
    printf("请输入字符串：");
    fgets(arr, 1000, stdin);
    int j = 0, i=0;
    
    while (arr[i] != '\n')
    {
        if (arr[i] != ' ')
        {
            arr[j] = arr[i];
            j++;
        }i++;
    }
    arr[j] = '\0';
    printf("%s", arr);
    free(arr);
    return 0;
}