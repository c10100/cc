#include <stdio.h>  // 标准输入输出（printf）
#include <stdlib.h> // 标准库（malloc 内存分配）
#include <string.h> // 字符串处理函数

// 定义队列节点结构体
typedef struct QueueNode
{
    int data;               // 数据域：存储整数数据
    struct QueueNode *prev; // 前驱指针：指向前一个节点
    struct QueueNode *next; // 后继指针：指向后一个节点
} QueueNode_t, *QueueNode_ptr;

QueueNode_ptr create_node(int data)
{
    // 用 malloc 分配一块 QueueNode_t 大小的内存
    QueueNode_ptr new_node = (QueueNode_ptr)malloc(sizeof(QueueNode_t));
    if (new_node == NULL) // 分配失败检查
    {
        printf("内存分配失败\n");
        return NULL;
    }

    new_node->data = data; // 将参数值存入数据域
    new_node->prev = NULL; // 新节点的前驱指针初始化为 NULL
    new_node->next = NULL; // 新节点的后继指针初始化为 NULL

    return new_node; // 返回新节点指针
}

QueueNode_ptr create_queue_head()
{
    QueueNode_ptr head = create_node(-1); // 创建一个数据域为-1的头节点
    head->next = head;                    // 头节点的next指向自己（形成一个自环）
    head->prev = head;                    // 头节点的prev指向自己（形成一个自环）

    return head; // 返回头指针
}

int isEmpty(QueueNode_ptr head)
{
    return head->next == head; // 头节点的next指向自己则链表为空
}

void traverse(QueueNode_ptr head)
{
    printf("队列元素："); // 输出链表元素
    if (isEmpty(head))    // 如果链表为空
    {
        printf("队列为空\n");
        return;
    }

    QueueNode_ptr tmp = head->next; // 从头节点的next开始遍历
    while (tmp != head)             // 遍历到头节点时结束
    {
        printf("%d ", tmp->data); // 输出节点数据
        tmp = tmp->next;          // 移动到下一个节点
    }
    printf("\n"); // 输出换行符
}

void insert_before(QueueNode_ptr current_node, QueueNode_ptr new_node)
{
    current_node->prev->next = new_node; // 旧的前节点的next指向新节点
    new_node->prev = current_node->prev; // 新节点的prev指向旧的前节点
    current_node->prev = new_node;       // current节点的prev指向新节点
    new_node->next = current_node;       // 新节点的next指向current节点
}
// insert_tail函数：在双向循环链表的尾节点之前插入新节点 O(1)
void enQueue(QueueNode_ptr head, QueueNode_ptr new_node)
{
    insert_before(head, new_node); // 在头节点的前之前插入新节点
}

void destroy_queue(QueueNode_ptr head)
{
    if (!isEmpty(head)) // 如果队列为空
    {
        QueueNode_ptr tmp = head->next; // 从头节点的next开始遍历
        while (tmp != head)             // 遍历到头节点时结束
        {
            QueueNode_ptr n = tmp->next;  // 保存下一个节点的指针
            tmp->prev = tmp->next = NULL; // 删除节点的前驱指针
            free(tmp);                    // 释放当前节点的内存
            tmp = n;                      // 移动到下一个节点
        }
    }
    head->next = head->prev = NULL; // 头节点的next指向自己（形成一个自环）
    free(head);                     // 释放头节点的内存
}

QueueNode_ptr delete_node(QueueNode_ptr node)
{
    if (node == NULL)
    {
        return NULL;
    }

    node->prev->next = node->next; // 旧的前节点的next指向旧的后继节点
    node->next->prev = node->prev; // 旧的后继节点的prev指向旧的前节点
    node->prev = NULL;             // 删除节点的前驱指针
    node->next = NULL;             // 删除节点的后继指针
    return node;                   // 返回删除的节点指针
}

QueueNode_ptr outQueue(QueueNode_ptr head)
{
    if (isEmpty(head)) // 如果队列为空
    {
        printf("队列为空\n");
        return NULL;
    }
    return delete_node(head->next); // 删除头节点的next节点（队列头节点）
}

int main()
{
    QueueNode_ptr h1 = create_queue_head(); // 创建一个队列   双向循环链表头节点  h1

    enQueue(h1, create_node(11)); // 在队列尾插入节点 11
    enQueue(h1, create_node(22)); // 在队列尾插入节点 22
    enQueue(h1, create_node(33)); // 在队列尾插入节点 33
    enQueue(h1, create_node(44)); // 在队列尾插入节点 44
    traverse(h1);                 // 遍历链表

    printf("出队： %d\n", outQueue(h1)->data); // 输出出队元素
    traverse(h1);                              // 遍历链表

    enQueue(h1, create_node(55)); // 在队列尾插入节点 55
    traverse(h1);                 // 遍历链表

    printf("出队： %d\n", outQueue(h1)->data); // 输出出队元素
    traverse(h1);                              // 遍历链表

    printf("出队： %d\n", outQueue(h1)->data); // 输出出队元素
    traverse(h1);                              // 遍历链表

    printf("出队： %d\n", outQueue(h1)->data); // 输出出队元素
    traverse(h1);                              // 遍历链表

    printf("出队： %d\n", outQueue(h1)->data); // 输出出队元素
    traverse(h1);                              // 遍历链表

    return 0; // 返回0表示程序正常结束
}
