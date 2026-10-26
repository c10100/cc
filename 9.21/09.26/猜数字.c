#include <stdio.h>
int main(void)
{
    int cnt = 0;
    int number, n, inp;
    int finished = 0;            // 标记游戏是否结束，0未结束，1结束
    scanf("%d %d", &number, &n); // 输入答案number，最多允许猜n次
    do
    {
        scanf("%d", &inp); // 读取本次猜测的数字
        cnt++;             // 猜测次数+1

        if (inp < 0)
        {
            printf("Game Over\n");
            finished = 1;
        }
        else if (inp > number)
        {
            printf("Too big\n");
        }
        else if (inp < number)
        {
            printf("Too small\n");
        }
        else
        {
            // 猜对的分支
            if (cnt == 1)
            {
                printf("Bingo!\n");
            }
            else if (cnt <= 3)
            {
                printf("Lucky You!\n");
            }
            else
            {
                printf("Good Guess!\n");
            }
            finished = 1;
        }

        // 判断是否已经用完n次机会，还没猜对就结束游戏
        if (cnt == n)
        {
            if (!finished)
            { // finished=0，说明还没有猜对
                printf("Game Over\n");
                finished = 1;
            }
        }

    } while (!finished); // finished为0就继续循环，finished=1退出

    return 0;
}