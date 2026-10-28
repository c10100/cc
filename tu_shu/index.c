#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ============ 1. 数据结构（按项目要求文档设计） ============ */

/* 图书链表节点：字段完全按要求文档来 */
typedef struct Book
{
    struct Book *prev;  // 指向上一个图书
    int id;             // 图书编号（删除/更新/借阅都靠它定位）
    char title[50];     // 书名
    char author[30];    // 作者
    char publisher[30]; // 出版社
    int year;           // 出版年份
    int stock;          // 库存数量：借阅减1，归还加1
    struct Book *next;  // 指向下一本书
} Book, *BookPtr;

// 借阅记录节点：每被借一次，就新增一条记录
typedef struct Record
{
    struct Record *prev; // 指向上一个记录
    char userName[20];   // 谁借的
    int bookId;          // 借的是哪本（存编号）
    char bookTitle[50];  // 书名冗余存一份，打印记录时不用回图书链表里找
    char borrowDate[15]; // 借阅日期
    int returned;        // 归还标记：0=未归还，1=已归还
    struct Record *next; // 指向下一条记录
} Record, *RecordPtr;

// 用户节点：给"管理员管理用户信息"用
typedef struct User
{
    struct User *prev; // 指向上一个用户
    char name[20];     // 用户名（登录和借阅记录都靠它关联）
    char password[20]; // 密码（登录时验证）
    struct User *next; // 指向下一个用户
} User, *UserPtr;

// 三条链表各有一个头指针，NULL 表示空表
// struct Book *bookHead = NULL;     /* 图书链表 */
// struct Record *recordHead = NULL; // 借阅记录链表
// struct User *userHead = NULL;     // 用户链表

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

// 根据图书ID查找图书（找节点型：借阅/归还/删除用它，返回第一个匹配的节点）
BookPtr findBookNodeById(BookPtr head, int id)
{
    if (bookIsEmpty(head))
        return NULL; // 空表直接返回找不到，不要只打印不返回
    BookPtr s = head->next;
    while (s != head)
    {
        if (s->id == id)
            return s;
        s = s->next;
    }
    return NULL;
}

// 查找并打印所有匹配的图书（查询展示型：只负责打印，返回找到几本）
// field: 1=按ID 2=按书名 3=按作者 4=按年份；keyword 统一按字符串传（数字字段内部转回整数）
int searchBooksByField(BookPtr head, int field, char *keyword)
{
    int count = 0;
    BookPtr s = head->next;
    while (s != head)
    {
        int match = 0; // 这个节点匹不匹配，先算出来再决定
        switch (field)
        {
        case 1:
            match = (s->id == atoi(keyword));
            break;
        case 2:
            match = (strcmp(s->title, keyword) == 0);
            break;
        case 3:
            match = (strcmp(s->author, keyword) == 0);
            break;
        case 4:
            match = (s->year == atoi(keyword));
            break;
        }
        if (match)
        {
            printf("%d %s %s %s %d %d\n", s->id, s->title, s->author, s->publisher, s->year, s->stock);
            count++;
        }
        s = s->next;
    }
    return count;
}

// 查找图书上一页下一页功能
void showBookPage(BookPtr bookHead)
{
    if (bookIsEmpty(bookHead))
    {
        printf("图书链表为空！\n");
        return;
    }

    // 第 1 步：数总数，算总页数
    int total = 0;
    BookPtr s = bookHead->next;
    while (s != bookHead)
    {
        total++;
        s = s->next;
    }

    int pageSize = 3;                                   // 每页 3 本，调小方便测试
    int totalPages = (total + pageSize - 1) / pageSize; // 向上取整：7本/3 = 3页
    int page = 1;                                       // 当前页码，从 1 开始

    while (1)
    {
        // 第 2 步：按"下标区间"只打印当前页那一小段
        int start = (page - 1) * pageSize; // 本页第一本的下标
        printf("---- 第 %d/%d 页 ----\n", page, totalPages);
        int i = 0;
        s = bookHead->next;
        while (s != bookHead && i < start + pageSize)
        {
            if (i >= start)
                printf("%d %s %s %s %d %d\n", s->id, s->title, s->author, s->publisher, s->year, s->stock);
            i++;
            s = s->next;
        }

        // 第 3 步：手动输入翻页
        printf("1.下一页 2.上一页 0.退出：");
        int cmd = 0, c;
        if (scanf("%d", &cmd) != 1)
            cmd = -1;
        while ((c = getchar()) != '\n' && c != EOF);
        if (cmd == 0)
            break;
        else if (cmd == 1 && page < totalPages)
            page++;
        else if (cmd == 2 && page > 1)
            page--;
        else
            printf("已经到底/到顶了！\n");
    }
}

// 删除图书
void deleteBookNode(BookPtr head, int id)
{
    BookPtr s = findBookNodeById(head, id);
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

// 查找某人借阅未还记录：返回第一条"用户名匹配且未归还"的记录，没有则返回 NULL
// （find 函数只负责找，不要在里面 printf——打印交给调用方决定）
RecordPtr findRecordNode(RecordPtr head, char *name)
{
    if (recordIsEmpty(head))
    {
        printf("链表为空");
    }
    RecordPtr s = head->next;
    while (s != head)
    {
        if (strcmp(s->userName, name) == 0 && s->returned == 0)
        {
            printf("\n");
        }
        s = s->next;
    }
    return s;
}

// 查找所有借阅记录
int showAllRecords(RecordPtr head)
{
    if (recordIsEmpty(head))
    {
        printf("链表为空");
    }
    RecordPtr s = head->next;
    while (s != head)
    {
        printf("%s %d %s %s %d\n", s->userName, s->bookId, s->bookTitle, s->borrowDate, s->returned);
        s = s->next;
    }
    printf("\n");
    return 0;
}

//  删除借阅记录
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

/* ========获取当前时间戳======== */

// 获取当前时间：调用方传一个 buf 进来，函数把时间字符串填进去
// （字符串不能通过 return 返回局部数组——局部变量函数一结束就销毁了）
void getCurrentTime(char *buf, int size)
{
    time_t now = time(NULL); // 获取当前时间戳
    if (now == (time_t)-1)
    {
        perror("time");
        buf[0] = '\0'; // 失败时给个空字符串，调用方拿到也不会崩
        return;
    }

    struct tm *local = localtime(&now); // 转为本地时间
    if (local == NULL)
    {
        perror("localtime");
        buf[0] = '\0';
        return;
    }

    strftime(buf, size, "%Y-%m-%d %H:%M:%S", local);
}

// 检查输入数字位数是否为n位：合格返回 1，不合格返回 0
// （纯判断函数，两个检查不过就直接 return 0，不需要循环重试——重试是 getIntInput 的事）
int checkNum(int integer, int n)
{
    char buf[20];
    int i;
    sprintf(buf, "%d", integer);

    if (strlen(buf) < n) // 检查1：长度够不够
        return 0;

    for (i = 0; buf[i] != '\0'; i++) // 检查2：逐个字符必须是数字（负数的'-'会被拦下）
    {
        if (buf[i] < '0' || buf[i] > '9')
            return 0;
    }
    return 1;
}

// 循环输入整数，直到输入合法（digit 位数字）；输 0 = 用户主动取消，返回 0
// 注意判断顺序：先看 scanf 成没成功（ret），再看你输的数（integer）
int getIntInput(char *prompt, int digit)
{
    int integer = 0;
    int c;
    while (1)
    {
        printf("%s(输入0结束)", prompt);
        int ret = scanf("%d", &integer);
        while ((c = getchar()) != '\n' && c != EOF)
            ; // 不管成败先把这一行吃干净，残留会毒害下一次 scanf
        if (ret == EOF)
            return 0;
        if (ret == 1)
        {
            if (integer == 0)
                return 0; // 0 = 用户取消；提示语由调用方按语境自己打
            if (checkNum(integer, digit))
                return integer;
        }
        printf("输入无效，请重新输入%d位数字！\n", digit);
    }
}

// 检查输入数字位数是否为n位
// int checkNum(int integer, int n)
// {
//     char buf[20];
//     int i, ok;

//     do
//     {
//         ok = 1; /* 先假设这次输入是合法的 */
//         // printf("请输入编号（不少于%d位数字）: ", n);
//         // scanf("%19s", buf); /* 当字符串读 */
//         sprintf(buf, "%d", integer);

//         if (strlen(buf) < n)
//         { /* 检查1：长度够不够 */
//             // printf("不足%d位！\n", n);
//             ok = 0;
//             return 0;
//             // continue; /* 直接进入下一轮 */
//         }

//         for (i = 0; buf[i] != '\0'; i++)
//         { /* 检查2：逐个字符看是不是数字 */
//             if (buf[i] < '0' || buf[i] > '9')
//             {
//                 // printf("必须全部是数字！\n");
//                 ok = 0;
//                 break;
//             }
//         }
//     } while (ok == 0);

//     integer = atoi(buf); /* 全部合格，字符串转成整数 */
//     return 1;
// }
