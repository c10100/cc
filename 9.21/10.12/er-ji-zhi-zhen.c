#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    printf("%d %p %p\n", a, &a, &a + 1);
    int **pa = &p;
    printf("%p %p %p\n", *pa, pa, pa + 1);
    return 0;
}