#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node, *pnode;


//创建一个链表节点
pnode createnode(int data)
{
    
}
//头节点创建
pnode create_head_node(int data)
{
    pnode head = (pnode)malloc(sizeof(pnode));
    head->data = -1;
    head->next = NULL;
}

int main()
{


    return 0;
}