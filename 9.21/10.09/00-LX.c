#include<stdio.h>
int main()
{
    char names[100][20];
    int count = 0;
    int a;
    char Storagenames[20];
    while(1)
    {
        printf("[1]记录姓名  [2]显示所有  [3]查询  [4]退出:");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                if(count>=100)
                {
                    printf("内存已满，无法记录！\n");
                    break;
                }
                printf("请输入姓名：");
                scanf("%s", Storagenames[count]);
                count++;
                printf("录入成功\n");
                break;
            case 2:
                if(count == 0)
                {
                    printf("暂无记录！\n");
                    break;
                }
                printf("====全部姓名====\n");
                for(int i = 0; i < count; i++)
                {
                    printf("%s\n", names[i]);
                }
                break;

            case 3:
                printf("请输入要查询的名字：");
                scanf("%s", a);
                int findFlag = 0;
                for(int i = 0; i < count; i++)
                {
                    
                    if(strcmp(names[i], a) == 0)
                    {
                        printf("找到了：%s\n", names[i]);
                        findFlag = 1;
                        break;
                    }
                }
                if(findFlag == 0)
                {
                    printf("没有找到\n");
                }
                break;

            case 4:
                printf("程序退出\n");
                return 0;

            default:
                printf("输入无效\n");
                break;


        }
    }
    return 0;
}