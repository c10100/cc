// 链表结构体
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

int main()
{
    LNode *L = NULL;    // 创建一个空链表
    LNode *tail = NULL; // 始终指向表尾结点
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // 新建一个结点并读入数据，
        LNode *s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &s->data);
        s->next = NULL;
        // 使用尾插法将其接入链表
        // 头指针L指向空代表当前链表为空
        if (tail == NULL)
        {                 // （L==NULL）也可以
            L = tail = s; // 头指针L和尾指针tail都指向s（新结点的地址）
        }
        else
        {
            tail->next = s; // 将第一个结点表尾指针指向新结点s
            tail = s;       // tail始终指向链表的最后一个结点
        }
    }
    printf("=============\n");
    for (LNode *p = L; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }
    return 0;
}