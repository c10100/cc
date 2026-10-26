#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./type.c"

userTypeList *userList;

userTypeList *createUserList() {
    userTypeList *head = malloc(sizeof(userTypeList));
    if (head == NULL) {
        printf("\n创建列表失败\n");
        return NULL;
    }
    head->userName = NULL;
    head->password = NULL;
    head->IDCode = NULL;
    head->next = head;
    head->prev = head;
    return head;
}

// 通过用户名搜索
userTypeList *getUserByUserName(char *name) {
    userTypeList *node = userList->next;
    while (node != userList && strcmp(node->userName, name) != 0) {
        node = node->next;
    }
    if (node == userList || strcmp(node->userName, name) != 0) {
        printf("\n不存在该用户\n");
        return NULL;
    }
    return node;
}

// 通过身份证搜索
userTypeList *getUserByIDcode(char *IDCode) {
    userTypeList *node = userList->next;
    while (node != userList && strcmp(node->IDCode, IDCode) != 0) {
        node = node->next;
    }
    if (node == userList || strcmp(node->IDCode, IDCode) != 0) {
        return NULL;
    }
    return node;
}

userTypeList *createUserNode(char *userName, char *password, char *IDCode, enum permission permission) {
    if (getUserByIDcode(IDCode)) {
        printf("\n创建用户：IDCode已存在\n");
        return NULL;
    }
    userTypeList *listNode = malloc(sizeof(userTypeList));
    if (!listNode) {
        printf("\n创建用户：创建失败\n");
        return NULL;
    }
    listNode->userName = userName;
    listNode->password = password;
    listNode->IDCode = IDCode;
    listNode->permission = permission;
    listNode->next = NULL;
    listNode->prev = NULL;
    return listNode;
}

// 插入
void insertUserList(userTypeList *data, userTypeList *insertNodeAddress) {
    if (!data) {
        printf("\n插入用户：数据为空\n");
        return;
    }

    userTypeList *node = userList->next;
    while (node != userList && node != insertNodeAddress) {
        node = node->next;
    }
    if (node != insertNodeAddress) {
        printf("\n插入用户：插入的位置不存在\n");
        return;
    }

    data->next = node->next;
    data->prev = node;
    node->next = data;
    data->next->prev = data;
}

// 尾插
void insertUserListAfter(userTypeList *data) {
    insertUserList(data, userList->prev);
}

// 删除
userTypeList *delUserNode(userTypeList *data) {
    userTypeList *node = userList->next;
    while (node != userList && node != data) {
        node = node->next;
    }
    if (node != data) {
        printf("\n删除用户：不存在该用户\n");
        return NULL;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    return node;
}
