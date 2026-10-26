// #include<stdio.h>
// int main()
// {
//     int seat[3][5] = {
//         {11, 12, 13, 14, 15},
//         {21, 22, 23, 24, 25},
//         {31, 32, 33, 34, 35}};
    
//     printf("%d\n", sizeof(seat));
//     printf("%p %p %d\n", &seat[0][0], &seat[0][0]+1, *(&seat[2][0]+1));
//     printf("%p %p %d\n", seat, seat+1, *(seat[0]+1));//*(seat+1)不可以
//     printf("%p %p\n\n", &seat, &seat+1);
//     printf("%p %p\n", seat[0], seat[0]+1);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    //二维字符数组：每行存一个名字字符串
    char names[50][20];
    int count = 0;   //记录当前已经录入多少个名字
    int select;      //菜单选项
    char names1[20]; //用于查询时存放待查找名字

    while(1)
    {
        //打印菜单，和题目一致
        printf("[1]记录姓名  [2]显示所有  [3]查询  [4]退出:");
        scanf("%d", &select);

        switch(select)
        {
            case 1:
                //记录姓名
                if(count >= 50)
                {
                    printf("名单已满，无法继续录入！\n");
                    break;
                }
                printf("请输入同学姓名：");
                scanf("%s", names[count]); //存入二维数组的第count行
                count++;
                printf("录入成功！\n");
                break;

            case 2:
                //显示所有已录入姓名
                if(count == 0)
                {
                    printf("暂无记录！\n");
                    break;
                }
                printf("====所有姓名====\n");
                for(int i = 0; i < count; i++)
                {
                    printf("%s\n", names[i]);
                }
                break;

            case 3:
                //查询姓名
                printf("请输入要查询的名字：");
                scanf("%s", names1);
                int findFlag = 0; //标记是否找到
                for(int i = 0; i < count; i++)
                {
                    //字符串比较函数strcmp，相等返回0
                    if(strcmp(names[i], names1) == 0)
                    {
                        printf("找到了：%s\n", names[i]);
                        findFlag = 1;
                        break;
                    }
                }
                if(findFlag == 0)
                {
                    printf("没有找到该同学！\n");
                }
                break;

            case 4:
                printf("程序退出\n");
                return 0;

            default:
                printf("输入选项无效，请重新选择！\n");
                break;
        }
    }
    return 0;
}
