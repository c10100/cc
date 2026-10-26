#include <stdio.h>
int main()
{
    while (1)
    {
        char num = '5';
        printf("请输入字符：");
        scanf(" %c", &num);
        if (num == '#')
        {
            break;
        }

        if ((num >= 'A' && num <= 'Z') || (num >= 'a' && num <= 'z'))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
// 判断输入的单个字符，如果是字符a到z  或者  A到Z ，则打印yes  ，否则打印no。如果输入'#' ，退出程序