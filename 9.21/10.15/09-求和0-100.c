#include <stdio.h>
// 100的求和
// int main()
// {
//     int sum = 0;
//     for (int i = 1; i <= 100; i++)
//     {
//         sum += i;
//     }

//     printf("0~100的和是：%d\n", sum);
//     return 0;
// }

// 100的求和 = 99的求和 + 100
//              = 98的求和 + 99
//              = 97的求和 + 98
//              = 96的求和 + 97
//              = 95的求和 + 96
//              .....
//              = 2的求和 + 3
//              = 1的求和 + 2
//              = 1的求和 = 1

// int f(int n)
// {
//     if (n == 1)
//     {
//         return 1; // 递归终止条件
//     }
//     printf("before n = %d\n", n);
//     return f(n - 1) + n;
// }

int f(int n)
{
    return n == 1 ? 1 : f(n - 1) + n;
}
int main()
{
    printf("%d\n", f(100));
}

// 100的阶乘 1*2*3*...*99*100
