#include <stdio.h>
#include <stdlib.h> // for malloc and free functions

typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 后驱指针域
} Node, *pNode;

// 创建链表节点
pNode createNode(int data)
{
    pNode newNode = (pNode)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 创建链表
pNode createList()
{
    pNode head = createNode(-1); // 创建头节点
    return head;
}

//  遍历链表 O(n)
void traverseList(pNode head)
{
    printf("-----------traverseList-----------\n");
    pNode tmp = head->next; // 当前节点指针指向头节点

    if (tmp == NULL)
    {
        printf("链表为空\n");
        return;
    }

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next; // 当前节点指针指向下一个有效节点
    }
    printf("\n");
}

// 根据值查找节点
pNode findNode(pNode head, int data)
{
    pNode tmp = head->next; // 当前节点指针指向头节点

    if (tmp == NULL)
    {
        printf("链表为空\n");
        return NULL;
    }

    while (tmp != NULL)
    {
        if (tmp->data == data)
        {
            return tmp; // 找到节点返回
        }
        tmp = tmp->next; // 当前节点指针指向下一个有效节点
    }
    return NULL; // 没找到节点返回NULL
}

// 尾部插入 O(n)
// void insertTail(pNode head, pNode newNode)
// {
//     pNode tmp = head; // 当前节点指针指向头节点
//     while (tmp->next != NULL)
//     {
//         tmp = tmp->next; // 当前节点指针指向下一个有效节点
//     }
//     // tmp就是链表的最后一个节点
//     tmp->next = newNode; // 将新节点插入到tmp节点后面
// }

// // 头部插入 O(1)
// void insertHead(pNode head, pNode newNode)
// {
//     newNode->next = head->next; // 把新节点的next 指向头节点的next(旧的第一个节点)
//     head->next = newNode;       // 把头节点的next 指向新节点
// }

// 在某个节点之后插入 O(1)
void insertAfter(pNode prevNode, pNode newNode)
{
    newNode->next = prevNode->next; // 把新节点的next 指向prevNode的next(旧的下一个节点)
    prevNode->next = newNode;       // 把prevNode的next 指向新节点
}

void insertTail(pNode head, pNode newNode)
{
    pNode tmp = head; // 当前节点指针指向头节点
    while (tmp->next != NULL)
    {
        tmp = tmp->next; // 当前节点指针指向下一个有效节点
    }
    // tmp就是链表的最后一个节点
    insertAfter(tmp, newNode); // 在tmp节点之后插入newNode
}

void insertHead(pNode head, pNode newNode)
{
    insertAfter(head, newNode); // 在head节点之后插入newNode
}

// 删除某个节点 O(n)    删除某个节点之后的节点 O(1)
pNode deleteNode(pNode head, pNode delNode)
{
    pNode tmp = head; // 当前节点指针指向头节点
    while (tmp != NULL && tmp->next != delNode)
    {
        tmp = tmp->next; // 当前节点指针指向下一个有效节点
    }
    // tmp就是delNode的前一个节点  或者是 tmp==NULL 链表中没有该节点
    if (tmp == NULL)
    {
        printf("链表中没有该节点\n");
        return NULL; // 没找到节点返回NULL
    }
    else
    {
        tmp->next = delNode->next; // 将tmp的next 指向delNode的next(旧的下一个节点)
        delNode->next = NULL;      // 将delNode的next 指向NULL
        // 大部分情况只是剔除节点 这个节点可能还有用  暂时不要free
        return delNode;
    }
}

// 释放链表 O(n)  head  11  22  33  44 不能先释放head节点

int main()
{

    pNode h1 = createList(); // 创建链表  本质是一个头节点
    printf("h1 = %p   h1->data = %d  h1->next = %p\n", h1, h1->data, h1->next);
    traverseList(h1);

    insertHead(h1, createNode(44));
    traverseList(h1);

    insertTail(h1, createNode(11));
    insertTail(h1, createNode(22));
    insertTail(h1, createNode(33));
    traverseList(h1);

    insertHead(h1, createNode(55));
    traverseList(h1);

    // // 根据值查找节点
    // pNode node = findNode(h1, 11);
    // printf("node %p  %d\n", node, node->data);

    // insertAfter(node, createNode(66)); // 在node节点之后插入66
    // traverseList(h1);

    // insertAfter(h1, createNode(77)); // 在h1节点(头节点)之后插入77
    // traverseList(h1);

    // // 在某个值后面插入
    // insertAfter(findNode(h1, 44), createNode(88)); // 在44节点之后插入88
    // traverseList(h1);

    // 剔除某个节点
    pNode n44 = deleteNode(h1, findNode(h1, 44));
    traverseList(h1);
    printf("n44 = %p  %d %p\n", n44, n44->data, n44->next);

    pNode n44_2 = deleteNode(h1, n44); // 删除链表中不存在的节点

    // 可能会把44节点 放进其他链表中去
    pNode h2 = createList(); // 转班的同学
    insertTail(h2, n44);     // 44节点转班走了  h2节点有用 // 除非学生退学  否则44节点不会被释放

    insertTail(h2, deleteNode(h1, findNode(h1, 22)));
    traverseList(h1);
    traverseList(h2);

    return 0;
}