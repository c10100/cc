#include <stdio.h>
int main()
{
    char names[5][5] = {"张三", "李四", "王五", "赵六", "韩七"};
    char course[5][5] = {"数学", "语文", "英语", "物理", "化学"};
    //char *course[5] = {"数学", "语文", "英语", "物理", "化学"};
    // char course[5][5] = {
    //     {'数', '学'},
    // };

    int scores[5][5] = {
        {81, 36, 13, 14, 15},
        {26, 35, 23, 24, 25},
        {51, 64, 33, 34, 35},
        {62, 52, 33, 34, 35},
        {58, 86, 33, 34, 35}};

    for (int j = 0; j < 5; j++)
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += scores[i][j];
        }

        printf("%s的平均成绩为%.2f\n", course[j], sum/5.0);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += scores[i][j];
        }

        printf("%s的平均成绩为%.2f\n", names[i], sum/5.0);
    }

    return 0;
}