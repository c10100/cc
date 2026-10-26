#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *array;   // 数组
    int front;    // 队头
    int size;     // 队列大小
    int capacity; // 数组容量
} Queue_t, *Queue_ptr;

// 初始化队列
Queue_ptr initQueue(int capacity)
{
    Queue_ptr queue = (Queue_ptr)malloc(sizeof(Queue_t));
    if (queue == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    queue->array = (int *)malloc(capacity * sizeof(int));
    if (queue->array == NULL)
    {
        printf("内存分配失败\n");
        free(queue);
        return NULL;
    }
    memset(queue->array, 0, capacity * sizeof(int)); // 初始化数组元素为0
    queue->front = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// 判断队列是否为空
int isEmpty(Queue_ptr queue)
{
    return queue->size == 0;
}

// 判断队列是否满
int isFull(Queue_ptr queue)
{
    return queue->size == queue->capacity;
}

// 扩容  O(n)
void expandQueue(Queue_ptr queue)
{
    int newCapacity = queue->capacity * 2;
    int *newArray = (int *)malloc(newCapacity * sizeof(int));
    if (newArray == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    memset(newArray, 0, newCapacity * sizeof(int)); // 初始化数组元素为0

    for (int i = 0; i < queue->size; i++)
    {
        newArray[i] = queue->array[(queue->front + i) % queue->capacity];
    }
    free(queue->array);
    queue->array = newArray;
    queue->front = 0;
    queue->capacity = newCapacity;
    printf("队列已扩容，容量 %d\n", queue->capacity); // 扩容
}

// 入队 O(1)   新入队的下标 rear=(front+size)/capacity
void enqueue(Queue_ptr queue, int value)
{
    if (isFull(queue)) // 队列满
    {
        // printf("队列已满，无法入队\n");
        // return;
        expandQueue(queue); // 扩容
    }

    if (isEmpty(queue)) // 队列为空
    {
        queue->front = 0;
        queue->array[0] = value;
        queue->size++;
    }
    else
    {
        int rear = (queue->front + queue->size) % queue->capacity;
        queue->array[rear] = value;
        queue->size++;
    }
}

// 出队
int dequeue(Queue_ptr queue)
{
    if (isEmpty(queue)) // 队列为空
    {
        printf("队列为空，无法出队\n");
        return -1;
    }
    int front = queue->array[queue->front]; // 队头元素
    queue->array[queue->front] = 0;         // 清空出队元素
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return front; // 返回出队元素
}

// 遍历队列

void traverseQueue(Queue_ptr queue)
{
    printf("----\n队列容量 %d ，队列大小 %d，队头 %d\n", queue->capacity, queue->size, queue->front);
    printf("队列元素："); // 遍历队列

    if (isEmpty(queue))
    {
        printf("队列为空 \n");
        return;
    }

    for (int i = queue->front; i < queue->front + queue->size; i++)
    {
        printf("%d ", queue->array[i % queue->capacity]);
    }
    printf("\n");

    printf("数组元素：");
    for (int i = 0; i < queue->capacity; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    Queue_ptr queue = initQueue(5);
    traverseQueue(queue);

    enqueue(queue, 11);
    enqueue(queue, 22);
    enqueue(queue, 33);
    traverseQueue(queue);

    printf("出队元素：%d\n", dequeue(queue));
    traverseQueue(queue);

    enqueue(queue, 44);
    enqueue(queue, 55);
    traverseQueue(queue);

    printf("出队元素：%d\n", dequeue(queue));
    traverseQueue(queue);

    enqueue(queue, 66);
    traverseQueue(queue);

    enqueue(queue, 77);
    traverseQueue(queue);

    enqueue(queue, 88);
    traverseQueue(queue);

    printf("出队元素：%d\n", dequeue(queue));
    traverseQueue(queue);

    printf("出队元素：%d\n", dequeue(queue));
    traverseQueue(queue);
}