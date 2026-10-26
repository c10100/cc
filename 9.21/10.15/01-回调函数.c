#include <stdio.h>

void xxx(void)
{
    printf("xxx\n");
}

// 回调函数 把某个函数作为另外一个函数的参数
void func(void (*p)(void)) // p 是一个函数指针
{
    printf("func start\n");
    p(); // 调用函数指针指向的函数
    printf("func end\n");
}

int main()
{

    func(xxx); // 传递函数xxx的地址给func函数

    return 0;
}