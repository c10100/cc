#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node_t, *node_p;

// 创建一个新节点
node_p create_node(int data)
{
    node_p new_node = (node_p)malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// 创建头节点
node_p create_list()
{
    node_p head = create_node(-1);
    head->prev = head;
    head->next = head;

    return head;
}

// 判断链表是否为空
int isempty(node_p head)
{
    return (head->next == head);
}

// 遍历链表
void traverselist(node_p head)
{
    if (isempty(head))
    {
        printf("链表为空\n");
    }
    node_p s = head->next;
    for (node_p i = head->next; s != head; s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

// 在某个节点之后插入节点
void insert_after(node_p current_node, node_p new_node)
{
    new_node->prev = current_node;
    new_node->next = current_node->next;
    current_node->next = new_node;
    new_node->next->prev = new_node;
}

// 在头节点之后插入节点
void insert_head(node_p head, node_p new_node)
{
    insert_after(head, new_node);
}

// 在某个节点之前插入节点
void insert_before(node_p current_node, node_p new_node)
{
    new_node->next = current_node;
    new_node->prev = current_node->prev;
    current_node->prev = new_node;
    new_node->prev->next = new_node;
}

// 在尾节点之后插入节点
void insert_tail(node_p head, node_p new_node)
{
    insert_before(head, new_node);
}

// 查找某个节点
node_p find_node(node_p head, int data)
{
    if (isempty(head))
    {
        printf("链表为空");
    }
    node_p s = head->next;
    while (s->data != data && s != head)
    {
        s = s->next;
    }
    if (s == head)
    {
        return NULL;
    }
    else
    {
        return s;
    }
}

// 删除某个节点
node_p delNode(node_p node)
{
    if (node == NULL)
    {
        return NULL;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// 销毁整个链表
void destroy_list(node_p head)
{
    if (isempty(head))
    {
        printf("链表为空");

        node_p p = head->next;
        while (p != head)
        {
            node_p temp = p;
            p = p->next;
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
    }
    head->next = head->prev = NULL;
    free(head);
}

int main()
{
    node_p head = create_list();
    insert_after(head, create_node(11));
    insert_head(head, create_node(22));
    insert_before(head, create_node(33));
    traverselist(head);
    node_p node = find_node(head, 33);
    if (node != NULL)
    {
        printf("找到了%d\n", node->data);
    }
    else
    {
        printf("找不到\n");
    }
    insert_before(node, create_node(55));
    traverselist(head);
    insert_tail(node, create_node(99));
    traverselist(head);
    insert_tail(head, create_node(01));
    traverselist(head);
    node_p s1 = delNode(node);
    traverselist(head);

    node_p s2 = create_list();
    insert_before(s2, s1);
    traverselist(s2);

    head = NULL;
    printf("%p", head);

    return 0;
}