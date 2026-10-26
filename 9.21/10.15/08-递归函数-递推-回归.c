#include <stdio.h>
#include <unistd.h>
/*

(1)问题模型本身要符合递归模型(递推模型)
(2)问题的解，当递归到一定层次时，答案是显而易见的，且能结束函数。
(3)先明确函数要实现的功能与参数的关系，暂不管功能具体的实现。
(4)呈现第n层与第n-1层的递推关系。

*/
void func(int n)
{
    if (n < 0)
    {
        return;
    }

    printf("func start n=%d\n", n); // 递推过程
    func(n - 1);
    printf("func end n=%d\n", n); // 回归过程
}

int main()
{

    func(5);

    return 0;
}