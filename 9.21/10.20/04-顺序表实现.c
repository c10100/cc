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

void traverseSequenceList(pSequenceList s);
pSequenceList sequenceListInit(int capacity);
int isFullSequenceList(pSequenceList s);
int insertSequenceList(pSequenceList s, int index, int value);
int insertTail(pSequenceList s, int value);
int insertHead(pSequenceList s, int value);
int deleteSequenceList(pSequenceList s, int index);
int findSequenceList(pSequenceList s, int value);
int expandArray(pSequenceList s);

int main()
{
    // 初始化顺序表
    pSequenceList s1 = sequenceListInit(5);
    traverseSequenceList(s1);

    // 尾插元素
    insertTail(s1, 11);
    insertTail(s1, 22);
    insertTail(s1, 33);
    traverseSequenceList(s1);

    // 头部插入
    insertHead(s1, 44);
    traverseSequenceList(s1);

    // 插入中间元素
    insertSequenceList(s1, 1, 55);
    traverseSequenceList(s1);

    // 删除元素
    // deleteSequenceList(s1, 2);
    // traverseSequenceList(s1);

    // // 删除头部元素
    // deleteSequenceList(s1, 0);
    // traverseSequenceList(s1);

    // // 删除尾部元素
    // deleteSequenceList(s1, s1->size - 1);
    // traverseSequenceList(s1);

    // 查找元素
    int index = findSequenceList(s1, 22);
    if (index != -1)
    {
        printf("索引为%d\n", index);
    }
    else
    {
        printf("不在顺序表中\n");
    }

    // 尾部插入
    insertTail(s1, 66);
    traverseSequenceList(s1);

    // 头部插入
    insertHead(s1, 77);
    insertHead(s1, 88);
    insertHead(s1, 99);
    insertHead(s1, 100);
    traverseSequenceList(s1);

    insertSequenceList(s1, 2, 888);
    traverseSequenceList(s1);

    // 删除值是22的元素
    deleteSequenceList(s1, findSequenceList(s1, 22));
    traverseSequenceList(s1);
}

// 遍历顺序表 O(n)
void traverseSequenceList(pSequenceList s)
{
    printf("顺序表元素容量为%d 当前元素个数为%d 元素列表：", s->capacity, s->size);
    for (int i = 0; i < s->capacity; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 初始化顺序表（创建顺序表/顺序表构造函数） 生成一个顺序表结构体 O(1)
pSequenceList sequenceListInit(int capacity)
{
    // 分配顺序表结构体内存 16字节
    pSequenceList s = (pSequenceList)malloc(sizeof(SequenceList));
    if (s == NULL)
    {
        printf("顺序表结构体内存分配失败\n");
        return NULL;
    }
    s->capacity = capacity;
    s->size = 0;

    // 申请数据内存  capacity * sizeof(int) 字节的空间
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

// 随机访问 O(1)
int getElement(pSequenceList s, int index)
{
    if (index < 0 || index >= s->size)
    {
        printf("随机访问位置无效\n");
        return -1;
    }
    return s->data[index];
}

// 判断顺序表是否满了 O(1)
int isFullSequenceList(pSequenceList s)
{
    return s->size == s->capacity;
}

// 插入元素 O(n)
int insertSequenceList(pSequenceList s, int index, int value)
{
    if (isFullSequenceList(s) == 1)
    {
        printf("顺序表已满，无法插入元素\n");
        // 扩容
        expandArray(s);
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

// 头部插入 O(n)
int insertHead(pSequenceList s, int value)
{
    return insertSequenceList(s, 0, value);
}

// 删除元素 O(n)
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

// 查找元素 O(n)
int findSequenceList(pSequenceList s, int value)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->data[i] == value)
        {
            return i;
        }
    }
    return -1; // 元素不存在
}

// 数组扩容 O(n) 新的数组大小为原数组大小的两倍 复制原来值到新的数组 释放就数组  修改结构体中的数据指针
int expandArray(pSequenceList s)
{
    printf("顺序表已满，进行扩容\n"); // 扩容
    // 申请新空间
    int *newData = (int *)malloc(2 * s->capacity * sizeof(int));
    if (newData == NULL)
    {
        printf("内存分配失败\n");
        return -1;
    }
    memset(newData, 0, 2 * s->capacity * sizeof(int)); // 初始化新数组为0
    // 复制原来值到新的数组
    for (int i = 0; i < s->size; i++)
    {
        newData[i] = s->data[i];
    }
    free(s->data);     // 释放旧数组
    s->data = newData; // 修改结构体中的数据指针
    s->capacity *= 2;  // 修改容量
    return 0;
}

// 销毁顺序表 顺序表析构函数
void destroySequenceList(pSequenceList s)
{
    if (s != NULL)
    {
        free(s->data); // 释放数据内存
        free(s);       // 释放顺序表结构体内存
    }
}