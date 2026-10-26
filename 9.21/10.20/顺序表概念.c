#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义顺序表结构体·
typedef struct
{
    int capacity; // 容量
    int size;     // 当前大小
    int *data;    // 数据入口
} SeqList, *pSeqList;

// 遍历顺序表·
void SeqListTraverse(SeqList s)
{
    printf("顺序表元素个数为%d 元素列表：", s.size);
    for (int i = 0; i < s.capacity; i++)
    {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

int main()
{

    // 初始化顺序表
    SeqList s1;
    s1.capacity = 5;                                    // 容量为5
    s1.size = 0;                                        // 当前有效元素个数为0
    s1.data = (int *)malloc(s1.capacity * sizeof(int)); // 分配内存
    memset(s1.data, 0, s1.capacity * sizeof(int));      // 初始化为0

    // 填充
    s1.data[0] = 11;
    s1.data[1] = 22;
    s1.data[2] = 33;
    s1.size = 3; // 当前有效元素个数为3

    // 遍历
    SeqListTraverse(s1);
}