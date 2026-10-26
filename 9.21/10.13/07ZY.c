// 7.判断字符串中是否存在字符串 strstr
// helloworld 是否存在lle
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main(void)
{
    char *arr1 = (char*)malloc(20*sizeof(char));
    strcpy(arr1, "helloworld");
    char *p = strstr(arr1, "llo");
    printf("%s", p);
}