#include <stdio.h>
#include <stdlib.h>
// 链表结构体
typedef struct node
{
    int data;
    struct node *next;
} node, *pnode;

// 创建链表节点
pnode createnode(int data)
{
    pnode s = (pnode)malloc(sizeof(node));//申请内存
    if (s == NULL)
    {
        printf("申请内存失败\n");
        return NULL;
    }
    s->data = data;
    s->next = NULL;
    return s;
}

// 新建头节点
pnode createlist()
{
    pnode head = createnode(-1);
    return head;
}

// 遍历链表
void traverselist(pnode head)
{
    pnode s = head->next; // 头节点指向当前节点
    if (s == NULL)
    {
        printf("当前链表为空");
        // return -1;
    }
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

// 根据值查找节点
pnode findnode(pnode head, int data)
{
    pnode s = head->next;//头结点，先找到头在哪
    if (s == NULL)
    {
        printf("当前链表为空");
        return NULL;
    }
    while (s != NULL)//逐个遍历
    {
        if (s->data == data)
        {
            return s;
        }
        s = s->next;
    }
    printf("没找到");
    return NULL;
}

// 节点后插入
void insertafter(pnode prevnode, pnode s)// 先进行插入位置前一个节点的查找(findnode())
{
    s->next = prevnode->next;
    prevnode->next = s;
}

// 尾部插入
void inserttail(pnode head, pnode s)//头节点，遍历链表，在最后进行插入节点
{
    pnode s1 = head;
    while (s1->next != NULL)
    {
        s1 = s1->next;
    }
    insertafter(s1, s);
}

// 头部插入
void inserthead(pnode head, pnode s)//对于insertafter的第0个位置进行插入
{
    s->next = head->next;
    head->next = s;
}

//删除某个节点
pnode deletenode(pnode head, pnode delnode)
{
    pnode s = head;
    while(s != NULL&&s->next!=delnode)
    {
        s = s->next;
    }
    // tmp就是delNode的前一个节点  或者是 tmp==NULL 链表中没有该节点
    if(s == NULL)
    {
        printf("链表中没有该节点");
        return NULL;
    }else{
        s->next = delnode->next;
        delnode->next = NULL;
        return delnode;//暂时没有free，可以转到其它链表
    }

}
int main()
{
    pnode s = createlist();
    printf("s=%p  s->data=%d  s->next=%p", s, s->data, s->next);
    traverselist(s);
    // 头插和尾插
    inserttail(s, createnode(11));
    inserttail(s, createnode(22));
    inserttail(s, createnode(33));
    inserthead(s, createnode(55));
    traverselist(s);
    // 某个数后插入
    insertafter(findnode(s, 22), createnode(76));
    traverselist(s);

    //查找某个数,之后在它后面插入一个数
    pnode node = findnode(s, 76);
    insertafter(node, createnode(66)); // 在node节点之后插入66
    traverselist(s);

    //删除某个节点
    deletenode(s, findnode(s, 66));
    traverselist(s);
    return 0;

}