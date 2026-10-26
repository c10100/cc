// 2、输入一个字符串ch，并做以下更改后输出：
// 1：如果里面有a或者A ，都输出*；
// 2：如果里面有b或者B ，都输出#；
// 其它的数据保持不变。如果输入的是字符串第一个字符ch[0]是x， 则退出程序
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int j = 20;
    char *a = (char *)malloc(j * sizeof(char));
    while (1)
    {
        if (scanf("%19s", a) != 1)
        {break;}
        if (a[0] == 'x')
        {
            break;
        }
        
        int b = sizeof(a) / sizeof(a[0]);
        for (int i = 0; i < b; i++)
        {
            if (a[i] == 'a' || a[i] == 'A')
            {
                a[i] = '*';
            }
            else if (a[i] == 'b' || a[i] == 'B')
            {
                a[i] = '#';
            }
            
        }
        printf("%s", a);
    }
    free(a);
    return 0;
}