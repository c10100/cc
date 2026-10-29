#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

//单链表 位查找操作
LNode* findkth(LNode *L, int n)
{
    if(n<0)return NULL;
    LNode *p = L;
    int i = 0;
    while(p!=NULL&&i<n)
    {
        p = p->next;
        // p = (*p).next;
        i++;
    }
    return p;
}

//头插法创建链表
int main()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));
    // 创建一个头结点，并让指针域指向空
    L->next = NULL;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &s->data);
        s->next = L->next;
        L->next = s;//这一步与上一步顺序不可更换
    }
    printf("=============\n");
    for (LNode *p = L->next; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }
    return 0;
}