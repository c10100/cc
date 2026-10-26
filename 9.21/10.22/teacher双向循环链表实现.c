#include <stdio.h>  // 标准输入输出（printf）
#include <stdlib.h> // 标准库（malloc 内存分配）
#include <string.h> // 字符串处理函数

// 定义双向循环链表的节点结构体
typedef struct Node
{
    int data;          // 数据域：存储整数数据
    struct Node *prev; // 前驱指针：指向前一个节点
    struct Node *next; // 后继指针：指向后一个节点
} Node_t, *Node_ptr;

// 创建节点的函数
// 参数 data：要存储的数据
// 返回值：新创建节点的指针，内存分配失败则返回 NULL
Node_ptr create_node(int data)
{
    // 用 malloc 分配一块 Node_t 大小的内存
    Node_ptr new_node = (Node_ptr)malloc(sizeof(Node_t));
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

// 创建双向循环链表 head头节点就是普通节点
Node_ptr create_list()
{
    Node_ptr head = create_node(-1); // 创建一个数据域为-1的头节点
    head->next = head;               // 头节点的next指向自己（形成一个自环）
    head->prev = head;               // 头节点的prev指向自己（形成一个自环）

    return head; // 返回头指针
}

// isEmpty函数：检查双向循环链表是否为空 O(1)
int isEmpty(Node_ptr head)
{
    return head->next == head; // 头节点的next指向自己则链表为空
}

// traverse函数：遍历双向循环链表并输出元素 O(n)
// 参数 head：双向循环链表的头节点
void traverse(Node_ptr head)
{
    printf("链表元素："); // 输出链表元素
    if (isEmpty(head))    // 如果链表为空
    {
        printf("链表为空\n");
        return;
    }

    Node_ptr tmp = head->next; // 从头节点的next开始遍历
    while (tmp != head)        // 遍历到头节点时结束
    {
        printf("%d ", tmp->data); // 输出节点数据
        tmp = tmp->next;          // 移动到下一个节点
    }
    printf("\n"); // 输出换行符
}

// insert_after函数：在节点 prev_node 之后插入新节点 new_node O(1)
// 参数 prev_node：要插入新节点的前驱节点
// 参数 new_node：要插入的新节点
void insert_after(Node_ptr prev_node, Node_ptr new_node)
{
    prev_node->next->prev = new_node; // 旧的后继节点的prev指向新节点
    new_node->next = prev_node->next; // 新节点的next指向旧的后继节点
    prev_node->next = new_node;       // 前驱节点的next指向新节点
    new_node->prev = prev_node;       // 新节点的prev指向前驱节点
}

// insert_head函数：在双向循环链表的头节点之后插入新节点 O(1)
void insert_head(Node_ptr head, Node_ptr new_node)
{
    insert_after(head, new_node); // 在头节点之后插入新节点
}

// insert_before函数：在节点 current_node 之前插入新节点 new_node O(1)
// 参数 current_node：要插入新节点的当前节点
// 参数 new_node：要插入的新节点
void insert_before(Node_ptr current_node, Node_ptr new_node)
{
    current_node->prev->next = new_node; // 旧的前节点的next指向新节点
    new_node->prev = current_node->prev; // 新节点的prev指向旧的前节点
    current_node->prev = new_node;       // current节点的prev指向新节点
    new_node->next = current_node;       // 新节点的next指向current节点
}

// insert_tail函数：在双向循环链表的尾节点之后插入新节点 O(1)
void insert_tail(Node_ptr head, Node_ptr new_node)
{
    insert_before(head, new_node); // 在头节点的前之前插入新节点
}

// find函数：在双向循环链表中查找数据为 data 的节点 O(n)
// 参数 head：双向循环链表的头节点
// 参数 data：要查找的数据
// 返回值：找到的节点指针，如果未找到则返回 NULL
Node_ptr find(Node_ptr head, int data)
{

    if (isEmpty(head)) // 如果链表为空
    {
        return NULL;
    }

    Node_ptr tmp = head->next;               // 从头节点的next开始遍历
    while (tmp->data != data && tmp != head) // 找到结束 或者 遍历到头节点时结束
    {
        tmp = tmp->next; // 移动到下一个节点
    }

    if (tmp == head) // 如果遍历到头节点仍未找到
    {
        return NULL; // 返回 NULL
    }
    else
    {               // 如果找到节点
        return tmp; // 返回找到的节点指针
    }
}

// delete_node函数：删除双向循环链表中的节点 node O(1)
// 参数 node：要删除的节点
// 返回值：删除的节点指针，如果未找到则返回 NULL
Node_ptr delete_node(Node_ptr node)
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

// 销毁双向循环链表的函数 O(n)
void destroy_list(Node_ptr head)
{
    if (!isEmpty(head)) // 如果链表为空
    {
        Node_ptr tmp = head->next; // 从头节点的next开始遍历
        while (tmp != head)        // 遍历到头节点时结束
        {
            Node_ptr n = tmp->next;       // 保存下一个节点的指针
            tmp->prev = tmp->next = NULL; // 删除节点的前驱指针
            free(tmp);                    // 释放当前节点的内存
            tmp = n;                      // 移动到下一个节点
        }
    }
    head->next = head->prev = NULL; // 头节点的next指向自己（形成一个自环）
    free(head);                     // 释放头节点的内存
}

int main()
{
    Node_ptr head = create_list(); // 创建一个双向循环链表 h1

    insert_head(head, create_node(11)); // 在头节点之后插入节点 11
    insert_head(head, create_node(22)); // 在头节点之后插入节点 22
    insert_head(head, create_node(33)); // 在头节点之后插入节点 33
    traverse(head);                     // 遍历链表并输出元素

    insert_tail(head, create_node(44)); // 在头节点的前之前插入节点 44
    insert_tail(head, create_node(55)); // 在头节点的前之前插入节点 55
    traverse(head);                     // 遍历链表并输出元素

    Node_ptr node11 = find(head, 11); // 查找数据为 ?? 的节点
    if (node11 != NULL)               // 如果找到节点
    {
        printf("找到节点 %d\n", node11->data); // 输出找到的节点数据
    }
    else
    {
        printf("未找到节点\n"); // 输出未找到节点的提示
    }

    insert_before(node11, create_node(66)); // 在节点 11 之前插入节点 66
    traverse(head);                         // 遍历链表并输出元素

    insert_after(node11, create_node(77)); // 在节点 11 之后插入节点 77
    traverse(head);                        // 遍历链表并输出元素

    Node_ptr node1 = delete_node(node11); // 删除节点 11
    traverse(head);                       // 遍历链表并输出元素

    Node_ptr node4 = delete_node(find(head, 44)); // 删除头节点
    traverse(head);                               // 遍历链表并输出元素

    Node_ptr head2 = create_list(); // 创建一个双向循环链表 h2
    insert_tail(head2, node1);      // 在头节点的前之前插入节点 node1
    insert_tail(head2, node4);      // 在头节点的前之前插入节点 node4
    traverse(head2);                // 遍历链表并输出元素

    delete_node(find(head, 100));

    destroy_list(head);  // 销毁双向循环链表 h1
    destroy_list(head2); // 销毁双向循环链表 h2
    head = head2 = NULL; // 将头指针置为 NULL

    printf("%p %p\n", head, head2);

    return 0; // 返回0表示程序正常结束
}
 