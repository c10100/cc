#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建结构体
typedef struct
{
    int capacity;
    int size;
    int *data;
} SequenceList, *pSequenceList;

// 遍历顺序表
void traversearray(pSequenceList s)
{
    printf("顺序表元素容量%d, 当前元素数量%d\n", s->capacity, s->size);
    for (int i = 0; i < s->capacity; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 初始化顺序表
pSequenceList sequenceListInit(int capacity)
{
    pSequenceList s = (pSequenceList)malloc(sizeof(SequenceList));
    if (s == NULL)
    {
        printf("分配内存失败");
        return NULL;
    }
    s->capacity = capacity;
    s->size = 0;
    s->data = (int *)malloc(capacity * sizeof(int));
    if (s->data == NULL)
    {
        printf("顺序表分配失败");
        free(s);
        return NULL;
    }
    memset(s->data, 0, capacity * sizeof(int));
    return s;
}

// 判断顺序表内部是否满了
int insertfull(pSequenceList s)
{
    return (s->size == s->capacity);
}

// 插入元素
int insertelement(pSequenceList s, int index, int num)
{
    if (insertfull(s))
    {
        printf("顺序表已满,无法插入\n");
        expandarray(s);
    }
    if (index < 0 || index > s->size)
    {
        printf("插入位置无效\n");
        return -1;
    }
    for (int i = s->size; i >= index; i--)
    {
        s->data[i + 1] = s->data[i];
    }
    s->data[index] = num;
    s->size++;
    return 0;
}

// 前插入
int H_insert(pSequenceList s, int num)
{
    insertelement(s, 0, num);
}

// 尾插入
int T_insert(pSequenceList s, int num)
{
    insertelement(s, s->size, num);
}

// 删除元素
int delelement(pSequenceList s, int index)
{
    if (index < 0 || index > s->size)
    {
        printf("删除位置无效\n");
        return -1;
    }
    for (int i = index; i <= s->size - 1; i++)
    {
        s->data[i] = s->data[i + 1];
    }
    s->data[s->size - 1] = 0;
    s->size--;
    return 0;
}

// 查找元素
int findelement(pSequenceList s, int num)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->data[i] == num)
        {
            return i;
        }
    }
    return -1;
}

// 内存扩展,数组扩容 O(n) 新的数组大小为原数组大小的两倍 复制原来值到新的数组 释放就数组  修改结构体中的数据指针
int expandarray(pSequenceList s)
{
    printf("顺序表满,进行扩容\n");
    int *newarray = (int *)malloc(2 * s->capacity * sizeof(int));
    if (newarray == NULL)
    {
        printf("内存分配失败");
        return -1;
    }
    memset(newarray, 0, 2 * s->capacity * sizeof(int));
    for (int i = 0; i < s->size; i++)
    {
        newarray[i] = s->data[i];
    }
    free(s->data);
    s->data = newarray;
    s->capacity *= 2;
    return 0;
}

int main()
{
    // 创建顺序表并初始化
    pSequenceList s = sequenceListInit(5);
    traversearray(s);

    // 插入元素
    insertelement(s, 0, 11);
    traversearray(s);

    // 头插入
    H_insert(s, 22);
    traversearray(s);

    // 尾插入
    T_insert(s, 55);
    traversearray(s);

    // 删除元素
    delelement(s, 1);
    traversearray(s);

    // 查找元素
    int index = findelement(s, 55);
    if (index != -1)
    {
        printf("找到了,下标为%d\n", index);
    }
    else
    {
        printf("不存在这个元素\n");
    }

    T_insert(s, 66);
    traversearray(s);
    T_insert(s, 100);
    traversearray(s);
    T_insert(s, 99);
    traversearray(s);
    T_insert(s, 98);
    traversearray(s);
}