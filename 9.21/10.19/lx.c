// #include <stdio.h>
// #define CHANGE(STR)  #STR  // #将文本STR转换成字符串
// int main()
// {
//     char *str = "hello" "world" "ikun";
//     printf("str = %s\n", str);
//     printf("CHANGE(STR)= %s\n", CHANGE(ikun i love you));    // #ikun i love you 转成"ikun i love you"
//     return 0;
// }

#include <stdio.h>
#define STRCAT(str1, str2)   str1##str2  // 将str1和str2标识连在一起
int main()
{
    int sum5 = 100;
    printf("sum5 =  %d\n", STRCAT(sum, 5));
    return 0;
}