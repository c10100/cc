#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.c"

/* 当前登录的用户名：借阅、归还、借阅查询都要用它 */
char currentUser[20] = "";

/* ============ 2. 函数声明 ============ */

void adminMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);      /* 管理员菜单 */
void addBook(BookPtr bookHead);                                                /* 图书录入 */
void deleteBook(BookPtr bookHead);                                             /* 图书删除 */
void updateBook(BookPtr bookHead);                                             /* 图书更新 */
void showBook(BookPtr bookHead);                                               /* 图书显示 */
void userManageMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead); /* 用户管理菜单 */
void addUser(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);        /* 添加用户 */
void deleteUser(UserPtr userHead);                                             /* 删除用户 */
void updateUser(UserPtr userHead);                                             /* 更新用户 */
void showUsers(UserPtr userHead);                                              /* 查看用户列表 */

void userMenu(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);      /* 用户菜单 */
void searchBook(BookPtr bookHead);                                            /* 图书查询 */
void borrowBook(UserPtr currentUser, BookPtr bookHead, RecordPtr recordHead); /* 图书借阅 */
void returnBook(UserPtr currentUser, BookPtr bookHead, RecordPtr recordHead); /* 图书归还 */
int showMyRecords(UserPtr currentUser, RecordPtr recordHead);                 /* 借阅查询 */
int adminLogin(void);                                                         /* 管理员登录 */
UserPtr userLogin(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead);  /* 用户登录：成功返回用户节点，失败返回 NULL */

/* ============ 3. 主框架 ============ */

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    UserPtr userHead = createUserHead();
    insertUserHead(userHead, createUserNode("z", "z"));
    insertUserHead(userHead, createUserNode("y", "y"));
    // traverseUserList(userHead);
    BookPtr bookHead = createBookHead();
    insertBookTail(bookHead, createBookNode(100001, "C语言程序设计", "王道", "清华大学出版社", 2023, 100));
    insertBookTail(bookHead, createBookNode(100002, "数据结构", "王道", "清华大学出版社", 2023, 100));
    insertBookTail(bookHead, createBookNode(100003, "算法", "王道", "清华大学出版社", 2023, 100));
    insertBookTail(bookHead, createBookNode(100004, "数据库", "王道", "清华大学出版社", 2023, 100));
    insertBookTail(bookHead, createBookNode(100005, "操作系统", "王道", "清华大学出版社", 2023, 100));
    insertBookTail(bookHead, createBookNode(100006, "网络", "王道", "清华大学出版社", 2023, 100));
    // traverseBookList(bookHead);
    RecordPtr recordHead = createRecordHead();
    insertRecordTail(recordHead, createRecordNode("z", 100001, "C语言程序设计", "2023-01-01", 0));
    insertRecordTail(recordHead, createRecordNode("z", 100002, "数据结构", "2023-01-02", 0));
    insertRecordTail(recordHead, createRecordNode("z", 100003, "算法", "2023-01-02", 0));
    insertRecordTail(recordHead, createRecordNode("z", 100004, "数据库", "2023-01-02", 0));
    insertRecordTail(recordHead, createRecordNode("z", 100005, "操作系统", "2023-01-02", 0));
    insertRecordTail(recordHead, createRecordNode("y", 100006, "网络", "2023-01-02", 0));
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
            UserPtr who = userLogin(userHead, bookHead, recordHead); /* 拿到登录成功的那个用户节点 */
            if (who != NULL)
                userMenu(who, bookHead, recordHead); /* 把"谁登录了"传进用户菜单 */
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
        {
            printf("输入无效，请重新选择！\n");
            choice = -1;
        } /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */
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
            updateBook(bookHead);
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
        {
            // printf("输入无效，请重新选择！\n");
            choice = -1;
        } /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */

        switch (choice)
        {
        case 1:
            addUser(userHead, bookHead, recordHead);
            break;
        case 2:
            deleteUser(userHead);
            break;
        case 3:
            updateUser(userHead);
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

void userMenu(UserPtr currentUser, BookPtr bookHead, RecordPtr recordHead)
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
        {
            // printf("输入无效，请重新选择！\n");
            choice = -1;
        } /* 非数字输入时 scanf 不消费也不更新，强制按无效选择处理 */

        switch (choice)
        {
        case 1:
            searchBook(bookHead);
            break;
        case 2:
            borrowBook(currentUser, bookHead, recordHead);
            break;
        case 3:
            returnBook(currentUser, bookHead, recordHead);
            break;
        case 4:
            showMyRecords(currentUser, recordHead);
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

// 图书信息录入
void addBook(BookPtr bookHead)
{
    int id = 0;
    char title[50] = {0};
    char author[30] = {0};
    char publisher[30] = {0};
    int year = 0;
    int stock = 0;
    int c;
    id = getIntInput("请输入图书ID（6位数字）：", 6);
    if (id == 0)
    {
        // printf("已取消图书录入，返回上级菜单\n");
        return;
    }
    if (findBookNodeById(bookHead, id) != NULL)
    {
        printf("图书id已存在！可选择更新图书信息\n");
        return;
    }
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
    printf("图书录入成功\n\n");
    printf("是否继续录入(1.是 0.否)：");
    int choice = 0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        addBook(bookHead);
    }
    else if (choice == 0)
    {
        printf("已取消录入其他图书，返回上级菜单\n");
    }
    else
    {
        printf("输入无效，请重新选择！\n");
    }
    // traverseBookList(bookHead);
}
// 图书信息删除
void deleteBook(BookPtr bookHead)
{
    if (bookIsEmpty(bookHead))
    {
        printf("图书链表为空，无法删除！\n");
        return;
    }
    int c;
    int id = 0;
    id = getIntInput("请输入要删除的图书ID（6位数字）：", 6);
    if (id == 0)
    {
        // printf("已取消图书删除，返回上级菜单\n");
        return;
    }
    // printf("请输入要删除的图书ID：");
    // if (scanf("%d", &id) != 1)
    // {
    //     printf("输入无效，请重新选择！\n");
    //     id = -1;
    // } /* 非数字输入时强制查不到，走"图书不存在"分支 */
    // while ((c = getchar()) != '\n' && c != EOF)
    //     ;
    BookPtr p = findBookNodeById(bookHead, id);
    if (p == NULL)
    {
        printf("图书不存在！\n");
        return;
    }
    deleteBookNode(bookHead, p->id); /* 函数按编号查找删除，传 p->id 而不是节点指针 */
    printf("图书删除成功！\n\n");
    printf("是否继续删除(1.是 0.否)：");
    int choice = 0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        deleteBook(bookHead);
    }
    else if (choice == 0)
    {
        printf("已取消删除图书，返回上级菜单\n");
    }
    else
    {
        printf("输入无效，请重新选择！\n");
    }
}
// 图书信息更新
void updateBook(BookPtr bookHead)
{
    int id = 0;
    int c;
    id = getIntInput("请输入要更新的图书ID（6位数字）：", 6);
    if (id == 0)
    {
        // printf("已取消图书更新，返回上级菜单\n");
        return;
    }
    // while ((c = getchar()) != '\n' && c != EOF)
    //     ;
    BookPtr p = findBookNodeById(bookHead, id);
    if (p == NULL)
    {
        printf("图书不存在！\n");
        return;
    }
    printf("当前图书信息：");
    printf("图书id：%d 图书名称：%s 图书作者：%s 图书出版社：%s 图书出版年份：%d 库存数量：%d\n", p->id, p->title, p->author, p->publisher, p->year, p->stock);
    printf("请选择要更新的图书信息：\n");
    printf("1. 图书名称\n");
    printf("2. 图书作者\n");
    printf("3. 图书出版社\n");
    printf("4. 图书出版年份\n");
    printf("5. 库存数量\n");
    printf("0. 返回上级菜单\n");
    printf("请选择: ");
    int choice = 0;
    if (scanf("%d", &choice) != 1)
        choice = -1;
    switch (choice)
    {
    case 1:
        printf("请输入新的图书名称：");
        scanf("%19s", p->title);
        break;
    case 2:
        printf("请输入新的图书作者：");
        scanf("%19s", p->author);
        break;
    case 3:
        printf("请输入新的图书出版社：");
        scanf("%19s", p->publisher);
        break;
    case 4:
        printf("请输入新的图书出版年份：");
        scanf("%d", &p->year);
        break;
    case 5:
        printf("请输入新的图书库存数量：");
        scanf("%d", &p->stock);
        break;
    case 0:
        return;
    default:
        printf("输入无效，请重新选择！\n");
        break;
    }
    printf("图书信息更新成功！\n\n");
    printf("是否继续更新(1.是 0.否)：");
    int choice1 = 0;
    if (scanf("%d", &choice1) != 1)
        choice1 = -1;
    if (choice1 == 1)
    {
        updateBook(bookHead);
    }
    else if (choice1 == 0)
    {
        printf("已取消更新图书，返回上级菜单\n");
    }
    else
    {
        printf("输入无效，请重新选择！\n");
    }
}
// 显示所有图书信息
void showBook(BookPtr bookHead)
{
    traverseBookList(bookHead);
    printf("\n");
}

// 用户注册
void addUser(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
{
    char name[20] = {0};
    char password[20] = {0};
    printf("请输入用户名：");
    scanf("%19s", name);
    if(findUserNode(userHead, name) != NULL)
    {
        printf("用户名已存在！\n");
        return;
    }
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
    // userLogin(userHead, bookHead, recordHead);
}
// 用户注销
void deleteUser(UserPtr userHead)
{
    if (userIsEmpty(userHead))
    {
        printf("用户链表为空，无法注销！\n");
        return;
    }
    char name[20] = {0};
    printf("请输入要注销的用户名：");
    scanf("%19s", name);
    UserPtr p = findUserNode(userHead, name);
    if (p == NULL)
    {
        printf("用户不存在！\n");
        return;
    }
    deleteUserNode(userHead, p->name); /* 函数按用户名查找删除，传 p->name 而不是节点指针 */
    printf("用户注销成功！\n");
}

// 用户信息更新
void updateUser(UserPtr userHead)
{
    char name[20] = {0};
    printf("请输入要更新的用户名：");
    scanf("%19s", name);
    UserPtr p = findUserNode(userHead, name);
    if (p == NULL)
    {
        printf("用户不存在！\n");
        return;
    }
    printf("当前用户信息：\n");
    printf("用户名：%s 密码：%s\n", p->name, p->password);
    printf("请选择要更新的用户信息：\n");
    printf("1. 用户名\n");
    printf("2. 密码\n");
    printf("0. 返回上级菜单\n");
    printf("请选择: ");
    int choice = 0;
    if (scanf("%d", &choice) != 1)
        choice = -1;
    switch (choice)
    {
    case 1:
        printf("请输入新的用户名：");
        scanf("%19s", p->name);
        break;
    case 2:
        printf("请输入新的密码：");
        scanf("%19s", p->password);
        break;
    case 0:
        return;
    default:
        printf("输入无效，请重新选择！\n");
        break;
    }
    printf("用户名：%s 密码：%s\n", p->name, p->password);
    printf("用户信息更新成功！\n");
}
// 显示所有用户信息
void showUsers(UserPtr userHead)
{
    traverseUserList(userHead);
}
// 查询图书：统一"选方式 → 读关键字 → 查找并打印"三段式
void searchBook(BookPtr bookHead)
{
    if (bookIsEmpty(bookHead))
    {
        printf("图书链表为空，无法查询！\n");
        return;
    }
    printf("请选择查询方式：\n");
    printf("1. 按图书ID查询\n");
    printf("2. 按图书名称查询\n");
    printf("3. 按图书作者查询\n");
    printf("4. 按图书出版年份查询\n");
    printf("0. 返回上级菜单\n");
    printf("请选择: ");
    int choice = 0;
    int c;
    if (scanf("%d", &choice) != 1)
        choice = -1;
    while ((c = getchar()) != '\n' && c != EOF)
        ; /* 不管选了什么先把这行残留清掉，后面的输入才不会被毒害 */
    if (choice == 0)
        return;
    if (choice < 1 || choice > 4)
    {
        printf("输入无效，请重新选择！\n");
        return;
    }

    char keyword[50] = {0};
    if (choice == 1) /* ID 特殊：要走 6 位数字循环校验 */
    {
        int id = getIntInput("请输入要查询的图书ID", 6);
        if (id == 0)
            // printf("已取消图书查询，返回上级菜单\n");
            return;
        sprintf(keyword, "%d", id); /* 转成字符串，和其它方式走同一条路 */
    }
    else /* 书名/作者/年份：统统按字符串读 */
    {
        printf("请输入关键字：");
        scanf("%49s", keyword);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (strcmp(keyword, "-1") == 0)
            return; /* 沿用"输 -1 取消"的约定 */
    }

    /* 找到几本打几本；一本都没有时按返回值统一提示 */
    if (searchBooksByField(bookHead, choice, keyword) == 0)
        printf("图书不存在！\n");
}
// 借阅图书
void borrowBook(UserPtr currentUser, BookPtr bookHead, RecordPtr recordHead)
{
    printf("查看图书：");
    showBookPage(bookHead);
    int id = 0;
    id = getIntInput("请输入要借阅的图书ID（6位数字）：", 6);
    if (id == 0)
    {
        // printf("已取消图书借阅，返回上级菜单\n");
        return;
    }
    BookPtr s = findBookNodeById(bookHead, id);
    // RecordPtr p = findRecordNode(recordHead, currentUser->name);
    if (s == NULL)
    {
        printf("图书不存在！\n");
        return;
    }
    if (s->stock <= 0)
    {
        printf("图书库存不足！\n");
        return;
    }
    RecordPtr p = recordHead->next;
    while (p != recordHead)
    {
        if (strcmp(p->userName, currentUser->name) == 0 && p->returned == 0 && s->id == p->bookId)
        {
            printf("您已经借阅过这本书\n");
            return;
            // found++;
        }
        p = p->next;
    }
    char time[64] = {0};
    getCurrentTime(time, sizeof(time)); 
    insertRecordTail(recordHead, createRecordNode(currentUser->name, id, s->title, time, 0));
    s->stock--;
    printf("图书借阅成功！\n\n");
    printf("是否继续借阅(1.是 0.否)：");
    int choice = 0;
    if (scanf("%d", &choice) != 1)
        choice = -1;
    int c2;
    while ((c2 = getchar()) != '\n' && c2 != EOF)
        ;
    if (choice == 1)
    {
        borrowBook(currentUser, bookHead, recordHead); 
    }
    else if (choice == 0)
    {
        printf("已取消借阅图书，返回上级菜单\n");
    }
    else
    {
        printf("输入无效，请重新选择！\n");
    }
}
// 归还图书
void returnBook(UserPtr currentUser, BookPtr bookHead, RecordPtr recordHead)
{
    int id = 0;
    int c;
    printf("当前登录用户为：%s，当前借阅记录如下：\n", currentUser->name);
    int count = showMyRecords(currentUser, recordHead);
    id = getIntInput("请输入要归还的图书ID（6位数字）：", 6);
    if (id == 0)
    {
        // printf("已取消图书归还，返回上级菜单\n");
        return;
    }
    /* 在"自己"的记录里找：用户名对 + 书号对 + 还没还过，三个条件同时满足才行 */
    RecordPtr p = recordHead->next;
    while (p != recordHead)
    {
        if (strcmp(p->userName, currentUser->name) == 0 && p->bookId == id && p->returned == 0)
            break;
        p = p->next;
    }
    if (p == recordHead)
    {
        printf("没有找到这本书的未归还借阅记录！\n");
        return;
    }
    BookPtr s = findBookNodeById(bookHead, p->bookId);
    if (s != NULL)
        s->stock++; /* 图书还在系统里才加库存；就算被管理员删了也只标记归还，不会崩 */
    p->returned = 1;
    count--;
    printf("图书归还成功！\n\n");
    if (count > 0)
    {
        printf("是否继续归还其他图书？（1. 是 2. 否）：");
        int choice = 0;
        if (scanf("%d", &choice) != 1)
            choice = -1;
        while ((c = getchar()) != '\n' && c != EOF)
            ; /* 不管选了什么先把这行残留清掉，后面的输入才不会被毒害 */
        if (choice == 0)
            return;
        if (choice < 1 || choice > 2)
        {
            printf("输入无效，请重新选择！\n");
            return;
        }
        if (choice == 1)
            returnBook(currentUser, bookHead, recordHead);
        else
            printf("已取消归还其他图书！\n");
    }
}

// 查询借阅记录：只显示当前登录用户自己的记录
int showMyRecords(UserPtr currentUser, RecordPtr recordHead)
{
    int found = 0;
    RecordPtr p = recordHead->next;
    while (p != recordHead)
    {
        if (strcmp(p->userName, currentUser->name) == 0 && p->returned == 0)
        {
            printf("借阅人：%s, 图书ID：%d, 图书名：%s, 借阅日期：%s, 是否归还：%d\n", p->userName, p->bookId, p->bookTitle, p->borrowDate, p->returned);
            found++;
        }
        p = p->next;
    }
    if (!found)
        printf("你还没有借阅记录！\n");
    return found;
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
    printf("帐号或密码错误\n");
    return 0;
}

// 用户登陆：成功返回匹配到的用户节点，失败返回 NULL
// （登录函数只负责验证，不要在里面直接进菜单——菜单由 main 拿到登录者后再进）
UserPtr userLogin(UserPtr userHead, BookPtr bookHead, RecordPtr recordHead)
{
    if (userIsEmpty(userHead))
    {
        printf("当前无账号，请先注册！\n");
        addUser(userHead, bookHead, recordHead);
        return NULL;
    }
    // traverseUserList(userHead);
    char accountp[20] = {0};
    char pass[20] = {0};
    printf("请输入帐号：");
    scanf("%19s", accountp);
    printf("请输入密码：");
    scanf("%19s", pass);

    UserPtr p = findUserNode(userHead, accountp); /* p 就是找到的节点，不用再 findUserNode 找一遍 */
    if (p != NULL && strcmp(p->password, pass) == 0)
    {
        printf("用户登陆成功\n");
        return p;
    }
    printf("帐号或密码错误\n");
    return NULL;
    // traverseUserList(userHead);
}
