#include <stdio.h>


// 随机访问数组  O(1)
int randomAccessArray(int *arr, int size, int index)
{
    // 检查索引是否有效
    if (index < 0 || index >= size)
    {
        printf("Invalid index\n");
        return -1;
    }

    printf("Element at index %d is %d\n", index, arr[index]);
    return 0;
}

// 遍历数组  O(n)
void traverseArray(int *arr, int capacity, int size)
{
    printf("Array size: %d,  elements: ", size);
    for (int i = 0; i < capacity; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 判断数组是否满了 O(1)
int isFull(int capacity, int size)
{
    return size == capacity;
}

// 尾部插入元素 O(1)
// void insertTail(int *arr, int capacity, int *size, int value)
// {
//     if (isFull(capacity, *size))
//     {
//         printf("Array is full\n");
//         return;
//     }
//     arr[*size] = value;
//     (*size)++;
// }

// 头部插入元素 O(n)  从后向前移动元素
// void insertHead(int *arr, int capacity, int *size, int value)
// {
//     // 判断数组是否满了
//     if (isFull(capacity, *size))
//     {
//         printf("Array is full\n");
//         return;
//     }

//     // 循环数组 向后移动元素
//     for (int i = *size - 1; i >= 0; i--)
//     {
//         // printf("%d -> %d\n", i, arr[i]);
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = value;
//     (*size)++;
// }

// 任意位置插入元素 O(n)  从后向前移动元素
void insert(int *arr, int capacity, int *size, int index, int value)
{
    // 判断数组是否满了
    if (isFull(capacity, *size))
    {
        printf("Array is full\n");
        return;
    }

    // 循环数组 向后移动元素
    for (int i = *size - 1; i >= index; i--)
    {
        // printf("%d -> %d\n", i, arr[i]);
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
    (*size)++;
}

void insertTail(int *arr, int capacity, int *size, int value)
{
    insert(arr, capacity, size, *size, value); // 调用任意位置插入元素函数
}

void insertHead(int *arr, int capacity, int *size, int value)
{
    insert(arr, capacity, size, 0, value); // 调用任意位置插入元素函数
}

int main()
{
    int nums[5] = {11, 22};
    int capacity = sizeof(nums) / sizeof(nums[0]); // 计算数组容量
    int size = 2;                                  // 实际元素的个数

    // 遍历数组  O(n)
    traverseArray(nums, capacity, size);

    // 随机访问数组  O(1)
    randomAccessArray(nums, size, 1);

    // 尾部插入元素  O(1)
    insertTail(nums, capacity, &size, 33);
    traverseArray(nums, capacity, size);

    // 头部插入元素  O(n)
    insertHead(nums, capacity, &size, 44);
    traverseArray(nums, capacity, size);

    // 任意位置插入元素  O(n)
    insert(nums, capacity, &size, 1, 55);
    traverseArray(nums, capacity, size);

    return 0;
}