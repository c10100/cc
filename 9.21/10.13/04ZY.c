// 将一个字符串倒序 "abcd" --->"dcba"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *arr = (char *)malloc(5 * sizeof(char));
    if (arr == NULL) return 1;
    strcpy(arr, "abcd");
    int len = strlen(arr);
    for (int i = 0, j = len-1; i < j; j--, i++)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("%s\n", arr);

    free(arr);
    return 0;
}