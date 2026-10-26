#include <stdio.h>
int main()
{
    char ch;
    int i = 0; // 空格
    int j = 0; // 大写字母
    int k = 0; // 小写字母
    int l = 0; // 其它字符
    printf("请输入字符，以输入'#'结束\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
        {
            i++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            j++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            k++;
        }
        else
        {
            l++;
        }
    }
    printf("空格有：%d\n", i);
    printf("大写字母有：%d\n", j);
    printf("小写字母有：%d\n", k);
    printf("其它字符有：%d\n", l);
    return 0;
}