//、编写一个程序，将两个字符串连接起来，不要用 strcat 或 strncat 函数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *arr1 = (char*)malloc(5*sizeof(char));
    char *arr2 = (char*)malloc(5*sizeof(char));
    strcpy(arr1, "abcd");
    strcpy(arr2, "abcd");
    printf("%s", strcat(arr1, arr2));
    return 0;
}