// 1、编写一个程序，该程序读取输入直到遇到#字符，然后报告读取的空格数目、读取的换行符数目以及读取的所有其它字符数目。
//  例如：输入:a 3 b
//  c%#
//  输出:spaces = 2, enter = 1, characters= 5
// #include <stdio.h>
// int main()
// {
//     int spaces = 0;
//     int enter = 0;
//     int characters = 0;
//     char a = 0;
//     printf("请输入：（'#'结束）");
//     while (1)
//     {
//         scanf("%c", &a);
//         if (a == '#')
//         {
//             break;
//         }
//         else if (a == ' ')
//         {
//             spaces++;
//         }
//         else if (a == '\n')
//         {
//             enter++;
//         }
//         else
//         {
//             characters++;
//         }
//     }
//     printf("spaces=%d, enter=%d, characters=%d", spaces, enter, characters);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *cnt = (int *)calloc(3, sizeof(int));
    if (!cnt)
        return 1;
    int ch;
    while ((ch = getchar()) != EOF && ch != '#')
    {
        if (ch == ' ')
            cnt[0]++;
        else if (ch == '\n')
            cnt[1]++;
        else
            cnt[2]++;
    }
    printf("spaces = %d, enter = %d, characters= %d\n", cnt[0], cnt[1], cnt[2]);
    free(cnt);
    return 0;
}