#include <stdio.h>
#include <unistd.h>

void func(void)
{
    printf("func start\n");
    // sleep(1); // 休眠1秒
    func();
    printf("func end\n");
}

int main()
{

    func();

    return 0;
}