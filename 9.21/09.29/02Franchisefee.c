#include<stdio.h>
int main()
{
    while(1)
    {
        int n = 0;
        printf("请输入营业额：");
        scanf("%d", &n);
        if(n<0)
        {
            printf("建议倒闭");
            goto acc;
        }
        if(n >= 1000000)
        {
            printf("需要提交的加盟费：%f\n", n*0.01);
        }else if (n<1000000&&n>=600000)
        {
            printf("需要提交的加盟费：%f\n", n*0.015);
        }else if(n<600000&&n>=400000)
        {
            printf("需要提交的加盟费：%f\n", n*0.03);
        }else if(n<400000&&n>=200000)
        {
            printf("需要提交的加盟费：%f\n", n*0.05);
        }else if(n<200000&&n>=100000)
        {
            printf("需要提交的加盟费：%f\n", n*0.0075);
        }else if(n<100000&&n>=0)
        {
            printf("需要提交的加盟费：%f\n", n*0.1);
        }
    }
    acc:
    return 0;
}