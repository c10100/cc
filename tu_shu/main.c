#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.c"

/* 当前登录的用户名：借阅、归还、借阅查询都要用它 */
char currentUser[20] = "";

/* ============ 2. 函数声明 ============ */

void adminMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead); /* 管理员菜单 */
void addBook(BookPtr bookHead);                     /* 图书录入 */
void deleteBook(BookPtr bookHead);                  /* 图书删除 */
void updateBook(void);                              /* 图书更新 */
void showBook(BookPtr bookHead);                    /* 图书显示 */
void userManageMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);              /* 用户管理菜单 */
void addUser(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);                     /* 添加用户 */
void deleteUser(UserPtr userHead);                  /* 删除用户 */
void updateUser(void);                              /* 更新用户 */
void showUsers(UserPtr userHead);                   /* 查看用户列表 */

void userMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead); /* 用户菜单 */
void searchBook(BookPtr bookHead);                     /* 图书查询 */
void borrowBook(void);                                 /* 图书借阅 */
void returnBook(void);                                 /* 图书归还 */
void showMyRecords(RecordPtr recordHead);              /* 借阅查询 */
int adminLogin(void);                                  /* 管理员登录 */
int userLogin(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);                       /* 用户登录 */

/* ============ 3. 主框架 ============ */

int main(void)
{
    UserPtr userHead = createUserHead();
    // insertUserHead(userHead, createUserNode("admin", "123456"));
    // traverseUserList(userHead);
    BookPtr bookHead = createBookHead();
    // insertBookTail(bookHead, createBookNode(1001, "C语言程序设计", "王道", "清华大学出版社", 2023, 100));
    // traverseBookList(bookHead);
    RecordPtr recordHead = createRecordHead();
    // traverseRecordList(recordHead);
    int identity; /* 存放身份选择 */

    while (1)
    { /* 大循环：不选 0 退出，就一直留在系统里 */
        int c;
        printf("\n======= 图书管理系统 登录选项=======\n");
        printf("1. 管理员登录\n");
        printf("2. 用户登录\n");
        printf("3. 注册新用户\n");
        printf("0. 退出系统\n");
        printf("请选择身份: ");
        if (scanf("%d", &identity) != 1)
            identity = -1;

        if (identity == 1)
        {
            if (adminLogin())
                adminMenu(userHead, bookHead, recordHead); /* 进管理员菜单（登录验证后面补） */
        }
        else if (identity == 2)
        {
            if (userLogin(userHead, bookHead, recordHead))
                userMenu(userHead, bookHead, recordHead); /* 进用户菜单（登录验证后面补） */
        }
        else if (identity == 3)
        {
            addUser(userHead, bookHead, recordHead); /* 注册新用户 */
        }
        else if (identity == 0)
        {
            break; /* 跳出大循环 → 程序结束 */
        }
        else
        {
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("输入无效，请重新选择！\n");
        }
    }

    printf("\n程序已结束，再见！\n");
    return 0;
}

/* ============ 4. 管理员端菜单 ============ */

void adminMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
{
    int choice;

    while (1)
    { /* 干完一个活自动回菜单，对应流程图的"是→功能选择" */
        int c;
        printf("\n----- 管理员菜单 功能选择-----\n");
        printf("1. 图书信息录入\n");
        printf("2. 图书信息删除\n");
        printf("3. 图书信息更新\n");
        printf("4. 图书信息显示\n");
        printf("5. 用户信息管理\n");
        printf("0. 返回上级菜单\n");
        printf("请选择: ");
        if (scanf("%d", &choice) != 1)
            choice = -1; /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (choice < 0 || choice > 5)
            continue;

        switch (choice)
        {
        case 1:
            addBook(bookHead);
            break;
        case 2:
            deleteBook(bookHead);
            break;
        case 3:
            updateBook();
            break;
        case 4:
            showBook(bookHead);
            break;
        case 5:
            userManageMenu(userHead, bookHead, recordHead);
            break; /* 进入用户管理子菜单 */
        case 0:
            return; /* 返回 main 的大循环 */
        default:
            printf("输入无效，请重新选择！\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}

/* 用户管理的子菜单：菜单套菜单，套路和 adminMenu 一模一样 */
void userManageMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
{
    int choice;

    while (1)
    {
        int c;
        printf("\n----- 用户信息管理 -----\n");
        printf("1. 添加新用户\n");
        printf("2. 删除用户\n");
        printf("3. 更新用户信息\n");
        printf("4. 查看用户列表\n");
        printf("0. 返回上级菜单\n");
        printf("请选择: ");
        if (scanf("%d", &choice) != 1)
            choice = -1; /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */

        switch (choice)
        {
        case 1:
            addUser(userHead, bookHead, recordHead);
            break;
        case 2:
            deleteUser(userHead);
            break;
        case 3:
            updateUser();
            break;
        case 4:
            showUsers(userHead);
            break;
        case 0:
            return; /* 回到 adminMenu */
        default:
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("输入无效，请重新选择！\n");
        }
    }
}

/* ============ 5. 用户端菜单 ============ */

void userMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
{
    int choice;

    while (1)
    {
        int c;
        printf("\n----- 用户菜单 功能选择-----\n");
        printf("1. 图书查询\n");
        printf("2. 图书借阅\n");
        printf("3. 图书归还\n");
        printf("4. 借阅查询\n");
        printf("0. 返回上级菜单\n");
        printf("请选择: ");
        if (scanf("%d", &choice) != 1)
            choice = -1; /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */

        switch (choice)
        {
        case 1:
            searchBook(bookHead);
            break;
        case 2:
            borrowBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            showMyRecords(recordHead);
            break;
        case 0:
            return;
        default:
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("输入无效，请重新选择！\n");
        }
    }
}

/* ============ 6. 功能空壳：下一步逐个填 ============ */

// 添加图书
void addBook(BookPtr bookHead)
{
    int id = 0;
    char title[50] = {0};
    char author[30] = {0};
    char publisher[30] = {0};
    int year = 0;
    int stock = 0;
    int c;
    printf("请输入图书ID：");
    if (scanf("%d", &id) != 1)
        id = -1; /* 非数字输入时保持-1，避免录入编号为0的图书 */
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("请输入图书名称：");
    scanf("%19s", title);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("请输入图书作者：");
    scanf("%19s", author);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("请输入图书出版社：");
    scanf("%19s", publisher);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("请输入图书出版年份：");
    scanf("%d", &year);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("请输入图书库存数量：");
    scanf("%d", &stock);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    insertBookTail(bookHead, createBookNode(id, title, author, publisher, year, stock));
    printf("图书录入成功\n");
    // traverseBookList(bookHead);
}
// 删除图书
void deleteBook(BookPtr bookHead)
{
    if (bookIsEmpty(bookHead))
    {
        printf("图书链表为空，无法删除！\n");
        return;
    }
    int c;
    int id = 0;
    printf("请输入要删除的图书ID：");
    if (scanf("%d", &id) != 1)
        id = -1; /* 非数字输入时强制查不到，走"图书不存在"分支 */
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    BookPtr p = findBookNode(bookHead, id);
    if (p == NULL)
    {
        printf("图书不存在！\n");
        return;
    }
    deleteBookNode(bookHead, p->id); /* 函数按编号查找删除，传 p->id 而不是节点指针 */
    printf("图书删除成功！\n");
}
    // 更新图书
    void updateBook(void) { printf("【图书更新】功能开发中...\n"); }
    // 显示所有图书
    void showBook(BookPtr bookHead)
    {
        traverseBookList(bookHead);
        printf("\n");
    }

    // 添加用户
    void addUser(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
    {
        char name[20] = {0};
        char password[20] = {0};
        printf("请输入用户名：");
        scanf("%19s", name);
        printf("请输入密码：");
        scanf("%19s", password);
        if (strcmp(name, "-1") == 0 && strcmp(password, "-1") == 0)
        {
            printf("管理员账号不能注册！\n");
            return;
        }
        insertUserTail(userHead, createUserNode(name, password));
        printf("用户注册成功！\n");
        // traverseUserList(userHead);
        userLogin(userHead, bookHead, recordHead);
    }
    // 删除用户
    void deleteUser(UserPtr userHead)
    {
        if (userIsEmpty(userHead))
        {
            printf("用户链表为空，无法删除！\n");
            return;
        }
        char name[20] = {0};
        printf("请输入要删除的用户名：");
        scanf("%19s", name);
        UserPtr p = findUserNode(userHead, name);
        if (p == NULL)
        {
            printf("用户不存在！\n");
            return;
        }
        deleteUserNode(userHead, p->name); /* 函数按用户名查找删除，传 p->name 而不是节点指针 */
        printf("用户删除成功！\n");
    }

    // 更新用户
    void updateUser(void) { printf("【更新用户】功能开发中...\n"); }
    // 显示所有用户
    void showUsers(UserPtr userHead)
    {
        traverseUserList(userHead);
    }
    // 查询图书
    void searchBook(BookPtr bookHead)
    {
        if (bookIsEmpty(bookHead))
            {
                printf("图书链表为空，无法查询！\n");
                return;
            }
        int id = 0;
        printf("请输入要查询的图书ID：");
        if (scanf("%d", &id) != 1)
            id = -1; /* 非数字输入时强制查不到，走"图书不存在"分支 */
        BookPtr p = findBookNode(bookHead, id);
        if (p == NULL)
        {
            printf("图书不存在！\n");
            return;
        }
        printf("图书信息：\n");
        printf("%d %s %s %s %d %d\n", p->id, p->title, p->author, p->publisher, p->year, p->stock);
    }
    // 借阅图书
    void borrowBook(void) { printf("【图书借阅】功能开发中...\n"); }
    // 归还图书
    void returnBook(void) { printf("【图书归还】功能开发中...\n"); }
    // 查询借阅记录
    void showMyRecords(RecordPtr recordHead)
    {
        if (recordIsEmpty(recordHead))
        {
            printf("借阅记录链表为空！\n");
            return;
        }
        traverseRecordList(recordHead);
        printf("\n");
    }

    // 管理员登陆
    int adminLogin(void)
    {
        char accountp[20] = {0};
        char pass[20] = {0};
        printf("请输入帐号：");
        scanf("%19s", accountp);
        printf("请输入密码：");
        scanf("%19s", pass);

        if (strcmp(accountp, "z") == 0 && strcmp(pass, "z") == 0)
        {
            printf("管理员登陆成功\n");
            return 1;
        }
        printf("帐号和密码错误\n");
        return 0;
    }

    // 用户登陆
    int userLogin(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
    {
        if (userIsEmpty(userHead))
        {
            printf("当前无账号，请先注册！\n");
            addUser(userHead, bookHead, recordHead);
            return 0;
        }
        // traverseUserList(userHead);
        char accountp[20] = {0};
        char pass[20] = {0};
        printf("请输入帐号：");
        scanf("%19s", accountp);
        printf("请输入密码：");
        scanf("%19s", pass);

        UserPtr p = userHead->next;
        while (p != userHead)
        {
            if (strcmp(p->name, accountp) == 0 && strcmp(p->password, pass) == 0)
            {
                printf("用户登陆成功\n");
                userMenu(userHead, bookHead, recordHead);
                break;
                return 1;
            }
            p = p->next;
        }
        printf("帐号和密码错误\n");
        return 0;
        // traverseUserList(userHead);
    }
