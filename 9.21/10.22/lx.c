#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *PNode;

// 创建链表
PNode createNode(int n, int arr[])
{
    //尾插法
    PNode L = NULL;    // 创建一个空链表
    PNode tail = NULL; // 始终指向表尾结点
    for(int i = 0; i<n; i++)
    {
        PNode s = (PNode)malloc(sizeof(Node));
        s->data = arr[i];
        s->next = NULL;
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
    /*头插法
    PNode head = (PNode)malloc(sizeof(Node));
    head->next = NULL;
    // int n = 0;
    // scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        PNode s = (PNode)malloc(sizeof(Node));
        // scanf("%d", s->data);
        s->data = arr[i];
        // head->next = s;
        // s->next = NULL;
        s->next = head->next;
        head->next = s;
    }
    */
    return L;
}

// 判断链表是否为空
int isEmpty(PNode head)
{
    return (head->next != NULL);
}

// 遍历链表
int traverseList(PNode L)
{
    if (isEmpty == 0)
    {
        printf("链表为空");
        return 0;
    }
    int count = 0;
    for (PNode i = L; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
        count++;
    }
    printf("\n");
    return count;
}

//最大值
int MAX(PNode L)
{
    if (isEmpty == 0)
    {
        printf("链表为空");
        return INT_MIN;
    }
    int max = L->next->data;
    for (PNode i = L; i != NULL; i = i->next)
    {
        if(i->data>max)
        {
            max = i->data;
        }
        // printf("%d ", i->data);
    }
    printf("\n");
    return max;
}

//统计某值出现几次
int list_count(PNode L)
{
    if (isEmpty == 0)
    {
        printf("链表为空");
        return 0;
    }
    int count = L->next->data;
    for (PNode i = L; i != NULL; i = i->next)
    {
        if(i->data>max)
        {
            max = i->data;
        }
        // printf("%d ", i->data);
    }
    printf("\n");
    return max;
}

int main()
{
    int arr[6] = {5, 3, 8, 3, 9, 3};
    PNode L = createNode(6, arr);

    //返回节点个数
    int count = traverseList(L);
    printf("%d", count);

    //最大值
    int max = MAX(L);
    printf("%d", max);
    return 0;
}