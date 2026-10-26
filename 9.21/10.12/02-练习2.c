#include <stdio.h>

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60};

    int *p1 = &array[0];
    int *p2 = array;

    printf("%p %p\n", p1, p1 + 1);
    printf("%p %p\n", p2, p2 + 1);

    printf("%d %d \n", array[4], *(array + 4));
    printf("%d %d\n", *(p1 + 4), p1[4]);
    return 0;
}
