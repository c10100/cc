#include <stdio.h>

int main()
{
    char a = 10;
    printf("a=%d &a=%p %p\n", a, &a, &a + 1);

    short b = 20;
    printf("b=%d &b=%p %p\n", b, &b, &b + 1);

    int c = 30;
    printf("c=%d &c=%p %p\n", c, &c, &c + 1);

    printf("sizeof(char)=%d sizeof(short)=%d sizeof(int)=%d \n",
           sizeof(char), sizeof(short), sizeof(int));
    printf("sizeof(a)=%d sizeof(b)=%d sizeof(c)=%d \n",
           sizeof(a), sizeof(b), sizeof(c));
    printf("sizeof(&a)=%d sizeof(&b)=%d sizeof(&c)=%d \n",
           sizeof(&a), sizeof(&b), sizeof(&c));

    // 32位系统指针大小为4字节  64位系统指针大小为8字节

    // 目标元素类型 *指针变量 = 初始化的值;
    char *pa = &a;
    printf("pa=%p *pa=%d\n", pa, *pa);

    // 指针变量的指针  二级指针
    char **ppa = &pa;
    printf("ppa=%p *ppa=%p **ppa=%d\n", ppa, *ppa, **ppa);

    // a = 111;
    // *pa = 112;
    // **ppa = 113;
    printf("a=%d \n", a);

    printf("%d %d\n", a, a + 1);
    printf("%p %p\n", pa, pa + 1);
    printf("%p %p\n", ppa, ppa + 1);
    // 指针偏移量 = n * 步长(sizeof(指针指向的目标元素类型))
    return 0;
}
