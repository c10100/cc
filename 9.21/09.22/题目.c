#include <stdio.h>
int mian(void)
{
    long a[4] = {1, 2, 3, 4};
    long *p1 = (long *)(&a + 1);
    long *p2 = (long *)((long)a + 1);
    printf("%lx\n", p1[-1]);
    printf("%lx\n", *p2);
    return 0;
}