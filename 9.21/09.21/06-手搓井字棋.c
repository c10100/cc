#include <stdio.h>

// 全局变量（当前这个文件里面任意位置都可以访问）  0代表空位  O X
char board[3][3] = {
    {0, 'X', 0},
    {0, 'O', 0},
    {0, 0, 'X'}};

void printHit()
{
    printf("棋盘序号：\n");
    int count = 1;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf(" %d ", count);
            if (col != 2)
            {
                printf("|");
            }

            count++;
        }
        if (row != 2)
        {
            printf("\n---+---+---\n");
        }
        else
        {
            printf("\n");
        }
    }
}

void printBoard()
{
    printf("\n=当前期棋盘=\n");
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {

            if (board[row][col] == 0)
            {
                printf("   ");
            }
            else
            {
                printf(" %c ", board[row][col]);
            }

            if (col != 2)
            {
                printf("|");
            }
        }
        if (row != 2)
        {
            printf("\n---+---+---\n");
        }
        else
        {
            printf("\n============\n");
        }
    }
}

int main()
{
    // 不管游戏逻辑 先测试函数是否可以用
    printHit();
    printBoard();

    return 0;
}
