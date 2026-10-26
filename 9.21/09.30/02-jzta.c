#include<stdio.h>
int main()
{
    char input = 0;
    scanf("%c", &input);
    int i, j, total, ch;
    total=input-'A'+1;//行数
    for(i = 0; i<total;i++ )//外层行数
    {
        for(j=0; j<total-i-1; j++)//前面空格
        {
            printf(" ");
        }
        for(ch='A'; ch<='A'+i; ch++)//前面一段字母
        {
            printf("%c", ch);
        }
        for(ch=input-1; ch>=input-i; ch--)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}


