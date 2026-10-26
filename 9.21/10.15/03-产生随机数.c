#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*

int rand(void); // 产生一个随机数，范围是0到RAND_MAX
void srand (unsigned int seed); // 设置随机数生成器的种子，用于生成随机数序列
time_t time(time_t *t); // 返回当前时间的时间戳

*/
int main()
{
    time_t t = time(NULL);
    printf("time() = %ld\n", t);

    srand(time(NULL));

    int res = rand();
    printf("rand() = %d\n", res);

    // 生成一个范围在0到9之间的随机数
    int res2 = rand() % 10;
    printf("res2 = %d\n", res2);

    // [012] - 1 =  [-1 0 1]
    int res3 = rand() % 3 - 1;
    printf("res3 = %d\n", res3);
    return 0;
}