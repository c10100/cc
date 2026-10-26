#include <stdio.h>

#define PI 3.14
#define XX 1 + 2
#define YY (1 + 2)
// #define    <宏名>    <字符串>
// #define    <宏名>（参数表）    <宏体>

int main()
{
    printf("PI = %f\n", PI);
    printf("XX = %d\n", XX);
    printf("XX = %d\n", XX * 3); // 1 + 2 * 3
    printf("YY = %d\n", YY);       //
    printf("YY = %d\n", YY * 3);   // (1 + 2) * 3
    //

    return 0;
}

/*


编译过程分为以下四个阶段：

1)预处理：处理预处理语句（#开头的语句），删除注释、头文件展开、宏替换...
            gcc  hello.c  -o  hello.i  -E
2)编译:将C语言代码转化为汇编语言
            gcc  hello.c  -o  hello.s  -S
3)汇编：将程序代码转化为二进制代码
            gcc  hello.c  -o  hello.o   -c
4)链接：将所有二进制代码合并起来，根据应用规则生成一个专门针对某个平台执行的应用程序镜像
            gcc  hello.c  -o  hello
*/