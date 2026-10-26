#include <stdio.h>
// 使用递归实现n的阶乘

int fun(int n)
{

    return n == 1 ? n : fun(n-1) * n;
}
int f(int n)
{
    if(n==1){
        return n;
    }
    return f(n-1)+n;
}

int main()
{
    printf("%d\n", fun(10));
    printf("%d", f(100));
    return 0;
}