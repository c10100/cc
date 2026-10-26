#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义顺序表结构体·
typedef struct
{
    int capacity; // 容量
    int size;     // 当前大小
    int *data;    // 数据入口
} SequenceList, *pSequenceList;

// 遍历顺序表
void TraverseSequenceList(pSequenceList s)
{
    printf("顺序表元素容量为%d 当前元素个数为%d 元素列表：", s->capacity, s->size);
    for (int i = 0; i < s->capacity; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 初始化顺序表 生成一个顺序表结构体
pSequenceList SequenceListInit(int capacity)
{
    pSequenceList s = (pSequenceList)malloc(sizeof(SequenceList));
    if (s == NULL)
    {
        printf("顺序表结构体内存分配失败\n");
        return NULL;
    }
    s->capacity = capacity;
    s->size = 0;
    s->data = (int *)malloc(capacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("顺序表的数据内存分配失败\n");
        free(s); // 释放顺序表结构体内存
        return NULL;
    }
    memset(s->data, 0, capacity * sizeof(int)); // 初始化数据为0
    return s;
}

// 判断顺序表是否满了
int isFullSequenceList(pSequenceList s)
{
    return s->size == s->capacity;
}

// 插入元素
int insertSequenceList(pSequenceList s, int index, int value)
{
    if (isFullSequenceList(s) == 1)
    {
        printf("顺序表已满，无法插入元素\n");
        return -1;
    }
    if (index < 0 || index > s->size)
    {
        printf("插入位置无效\n");
        return -1;
    }

    for (int i = s->size - 1; i >= index; i--)
    {
        s->data[i + 1] = s->data[i];
    }
    s->data[index] = value;
    s->size++;
    return 0;
}

// 尾插元素
int insertTail(pSequenceList s, int value)
{
    return insertSequenceList(s, s->size, value);
}

// 头部插入
int insertHead(pSequenceList s, int value)
{
    return insertSequenceList(s, 0, value);
}

// 删除元素
int deleteSequenceList(pSequenceList s, int index)
{
    if (index < 0 || index >= s->size)
    {
        printf("删除位置无效\n");
        return -1;
    }
    for (int i = index; i < s->size - 1; i++)
    {
        s->data[i] = s->data[i + 1];
    }
    s->data[s->size - 1] = 0;
    s->size--;
    return 0;
}

int main()
{
    // 初始化顺序表
    pSequenceList s1 = SequenceListInit(10);
    TraverseSequenceList(s1);

    // 尾插元素
    insertTail(s1, 11);
    insertTail(s1, 22);
    insertTail(s1, 33);
    TraverseSequenceList(s1);

    // 头部插入
    insertHead(s1, 44);
    TraverseSequenceList(s1);

    // 插入中间元素
    insertSequenceList(s1, 1, 55);
    TraverseSequenceList(s1);

    // 删除元素
    deleteSequenceList(s1, 2);
    TraverseSequenceList(s1);

    // 删除头部元素
    deleteSequenceList(s1, 0);
    TraverseSequenceList(s1);

    // 删除尾部元素
    deleteSequenceList(s1, s1->size - 1);
    TraverseSequenceList(s1);
}