#include <stdio.h>

// f(n) = f(n - 1) + f(n - 2)      f(0)=0  f(1) = 1
int f(int n)
{
    return n <= 1 ? n : f(n - 1) + f(n - 2);
}
int main()
{
    printf("%d\n", f(10));

    return 0;
}

/*
考试题：手写代码
    求和（递归）
    阶乘（递归）
    斐波那契数列（递归）
    杨辉三角（循环）（递归）

    查找 暴力搜索 二分查找
    排序 选择排序 冒泡排序 快速排序 插入排序

*/