#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode_t, *StackNode_ptr;

StackNode_ptr createStackNode(int data)
{
    StackNode_ptr newNode = (StackNode_ptr)malloc(sizeof(StackNode_t));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 栈的入栈操作
void push(StackNode_ptr stack, StackNode_ptr newNode)
{
    newNode->next = stack->next;
    stack->next = newNode;
}

// 遍历栈
void traverseStack(StackNode_ptr stack)
{
    StackNode_ptr tmp = stack->next;
    if (tmp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// 栈的出栈操作
StackNode_ptr pop(StackNode_ptr stack)
{
    StackNode_ptr tmp = stack->next;
    if (tmp == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    stack->next = tmp->next;
    tmp->next = NULL; // 断开连接
    return tmp;
}

int main()
{
    // 创建一个空栈  链表的头节点
    StackNode_ptr s1 = createStackNode(-1);

    // 入栈
    push(s1, createStackNode(11));
    push(s1, createStackNode(22));
    push(s1, createStackNode(33));
    traverseStack(s1); // 输出: 33 22 11

    // 出栈
    printf("Pop: %d\n", pop(s1)->data); // 输出: 33
    traverseStack(s1);                  // 输出: 22 11

    printf("Pop: %d\n", pop(s1)->data); // 输出: 22
    traverseStack(s1);                  // 输出: 11

    printf("Pop: %d\n", pop(s1)->data); // 输出: 11
    traverseStack(s1);                  // 输出: 空

    return 0;
}
