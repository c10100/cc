#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============ 1. 数据结构（按项目要求文档设计） ============ */

/* 图书链表节点：字段完全按要求文档来 */
typedef struct Book
{
    struct Book *prev;  // 指向上一个图书
    int id;             /* 图书编号（删除/更新/借阅都靠它定位） */
    char title[50];     /* 书名 */
    char author[30];    /* 作者 */
    char publisher[30]; /* 出版社 */
    int year;           /* 出版年份 */
    int stock;          /* 库存数量：借阅减1，归还加1 */
    struct Book *next;  /* 指向下一本书 */
} Book, *BookPtr;

/* 借阅记录节点：每被借一次，就新增一条记录 */
typedef struct Record
{
    struct Record *prev; // 指向上一个记录
    char userName[20];   /* 谁借的 */
    int bookId;          /* 借的是哪本（存编号） */
    char bookTitle[50];  /* 书名冗余存一份，打印记录时不用回图书链表里找 */
    char borrowDate[15]; /* 借阅日期 */
    int returned;        /* 归还标记：0=未归还，1=已归还 */
    struct Record *next; /* 指向下一条记录 */
} Record, *RecordPtr;

/* 用户节点：给"管理员管理用户信息"用 */
typedef struct User
{
    struct User *prev; // 指向上一个用户
    char name[20];     /* 用户名（登录和借阅记录都靠它关联） */
    char password[20]; /* 密码（登录时验证） */
    struct User *next; /* 指向下一个用户 */
} User, *UserPtr;

/* 三条链表各有一个头指针，NULL 表示空表 */
// struct Book *bookHead = NULL;     /* 图书链表 */
// struct Record *recordHead = NULL; /* 借阅记录链表 */
// struct User *userHead = NULL;     /* 用户链表 */

// 创建用户节点
UserPtr createUserNode(char *name, char *password)
{
    UserPtr p = (UserPtr)malloc(sizeof(User));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    strcpy(p->name, name);
    strcpy(p->password, password);
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// 创建用户头节点
UserPtr createUserHead()
{
    UserPtr userHead = createUserNode("-1", "-1");
    userHead->prev = userHead;
    userHead->next = userHead;
    return userHead;
}

// 判断链表是否为空
int userIsEmpty(UserPtr userHead)
{
    return (userHead->next == userHead);
}

// 遍历链表
void traverseUserList(UserPtr head)
{
    if (userIsEmpty(head))
    {
        printf("用户链表为空！\n");
        return;
    }
    UserPtr p = head->next;
    while (p != head)
    {
        printf("%s %s\n", p->name, p->password);
        p = p->next;
    }
    printf("\n");
}

// 插入用户节点
void insertUserNode(UserPtr currentNode, UserPtr newNode)
{
    newNode->prev = currentNode;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    newNode->next->prev = newNode;
}

// 在头节点之后插入节点
void insertUserHead(UserPtr head, UserPtr newNode)
{
    insertUserNode(head, newNode);
}

// 在某个节点之前插入节点
void insertUserBefore(UserPtr currentNode, UserPtr newNode)
{
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
    newNode->prev->next = newNode;
}

// 在尾节点之后插入节点
void insertUserTail(UserPtr head, UserPtr newNode)
{
    insertUserBefore(head, newNode);
}

// 查找用户
UserPtr findUserNode(UserPtr head, char *name)
{
    if (userIsEmpty(head))
    {
        printf("链表为空");
    }
    UserPtr s = head->next;
    while (strcmp(s->name, name) != 0 && s != head)
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

// 删除用户
void deleteUserNode(UserPtr head, char *name)
{
    UserPtr s = findUserNode(head, name);
    if (s == NULL)
    {
        printf("用户不存在！\n");
        return;
    }
    s->prev->next = s->next;
    s->next->prev = s->prev;
    s->prev = NULL;
    s->next = NULL;
    free(s);
}

/* ========创建图书节点======== */

// 创建图书节点
BookPtr createBookNode(int id, char *title, char *author, char *publisher, int year, int stock)
{
    BookPtr p = (BookPtr)malloc(sizeof(Book));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    p->id = id;
    strcpy(p->title, title);
    strcpy(p->author, author);
    strcpy(p->publisher, publisher);
    p->year = year;
    p->stock = stock;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// 创建图书头节点
BookPtr createBookHead()
{
    BookPtr bookHead = createBookNode(-1, "-1", "-1", "-1", -1, -1);
    bookHead->prev = bookHead;
    bookHead->next = bookHead;
    return bookHead;
}

// 判断图书链表是否为空
int bookIsEmpty(BookPtr BookHead)
{
    return (BookHead->next == BookHead);
}

// 遍历图书链表
void traverseBookList(BookPtr head)
{
    if (bookIsEmpty(head))
    {
        printf("图书链表为空！\n");
        return;
    }
    BookPtr p = head->next;
    while (p != head)
    {
        printf("%d %s %s %s %d %d\n", p->id, p->title, p->author, p->publisher, p->year, p->stock);
        p = p->next;
    }
    printf("\n");
}

// 插入图书节点
void insertBookNode(BookPtr currentNode, BookPtr newNode)
{
    newNode->prev = currentNode;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    newNode->next->prev = newNode;
}

// 在图书头节点之后插入节点
void insertBookHead(BookPtr head, BookPtr newNode)
{
    insertBookNode(head, newNode);
}

// 在某个节点之前插入节点
void insertBookBefore(BookPtr currentNode, BookPtr newNode)
{
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
    newNode->prev->next = newNode;
}

// 在尾节点之后插入节点
void insertBookTail(BookPtr head, BookPtr newNode)
{
    insertBookBefore(head, newNode);
}

// 查找图书
BookPtr findBookNode(BookPtr head, int id)
{
    if (bookIsEmpty(head))
    {
        printf("链表为空");
    }
    BookPtr s = head->next;
    while (s->id != id && s != head)
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

// 删除图书
void deleteBookNode(BookPtr head, int id)
{
    BookPtr s = findBookNode(head, id);
    if (s == NULL)
    {
        printf("图书不存在！\n");
        return;
    }
    s->prev->next = s->next;
    s->next->prev = s->prev;
    s->prev = NULL;
    s->next = NULL;
    free(s);
}

/* ========创建借阅记录节点======== */

// 创建借阅记录节点
RecordPtr createRecordNode(char *userName, int bookId, char *bookTitle, char *borrowDate, int returned)
{
    RecordPtr p = (RecordPtr)malloc(sizeof(Record));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    strcpy(p->userName, userName);
    p->bookId = bookId;
    strcpy(p->bookTitle, bookTitle);
    strcpy(p->borrowDate, borrowDate);
    p->returned = returned;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// 创建借阅记录头节点
RecordPtr createRecordHead()
{
    RecordPtr recordHead = createRecordNode("-1", -1, "-1", "-1", -1);
    recordHead->prev = recordHead;
    recordHead->next = recordHead;
    return recordHead;
}

// 判断借阅记录链表是否为空
int recordIsEmpty(RecordPtr RecordHead)
{
    return (RecordHead->next == RecordHead);
}

// 遍历借阅记录链表
void traverseRecordList(RecordPtr head)
{
    if (recordIsEmpty(head))
    {
        printf("借阅记录链表为空！\n");
        return;
    }
    RecordPtr p = head->next;
    while (p != head)
    {
        printf("%s %d %s %s %d\n", p->userName, p->bookId, p->bookTitle, p->borrowDate, p->returned);
        p = p->next;
    }
    printf("\n");
}

// 插入借阅记录节点
void insertRecordNode(RecordPtr currentNode, RecordPtr newNode)
{
    newNode->prev = currentNode;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    newNode->next->prev = newNode;
}

// 在借阅记录头节点之后插入节点
void insertRecordHead(RecordPtr head, RecordPtr newNode)
{
    insertRecordNode(head, newNode);
}

// 在某个节点之前插入节点
void insertRecordBefore(RecordPtr currentNode, RecordPtr newNode)
{
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
    newNode->prev->next = newNode;
}

// 在尾节点之后插入节点
void insertRecordTail(RecordPtr head, RecordPtr newNode)
{
    insertRecordBefore(head, newNode);
}

// 查找借阅记录
RecordPtr findRecordNode(RecordPtr head, char *name)
{
    if (recordIsEmpty(head))
    {
        printf("链表为空");
    }
    RecordPtr s = head->next;
    while (strcmp(s->userName, name) != 0 && s != head)
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

// 删除借阅记录
void deleteRecordNode(RecordPtr head, char *name)
{
    RecordPtr s = findRecordNode(head, name);
    if (s == NULL)
    {
        printf("记录不存在！\n");
        return;
    }
    s->prev->next = s->next;
    s->next->prev = s->prev;
    s->prev = NULL;
    s->next = NULL;
    free(s);
}

// int main()
// {
    // UserPtr userHead = createUserHead();
    // insertUserHead(userHead, createUserNode("admin", "123456"));
    // traverseUserList(userHead);
    // insertUserTail(userHead, createUserNode("user1", "123456"));
    // traverseUserList(userHead);
    // RecordPtr recordHead = createRecordHead();
    // insertRecordHead(recordHead, createRecordNode("user1", 1, "book1", "2026-1-1", 0));
    // traverseRecordList(recordHead);
    // insertRecordTail(recordHead, createRecordNode("user2", 2, "book2", "2026-1-2", 0));
    // traverseRecordList(recordHead);
//     return 0;
// }
