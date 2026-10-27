// #include <stdio.h>

// int main(void) // 推荐使用 void
// {
//     int c; // 必须使用 int 来接 getchar 的返回值

//     for (int i = 0; i < 5; i++)
//     {
//         c = getchar();
        
//         // 检查是否遇到文件结束符(EOF)
//         if (c == EOF)
//         {
//             printf("输入提前结束！\n");
//             break; // 如果输入提前结束，跳出循环
//         }
        
//         putchar(c);
//     }

//     return 0; // 规范：返回 0 表示成功
// }


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define MAX_USERS 100     // 系统最多能存多少个用户
// #define MAX_LEN 50        // 用户名和密码的最大长度

// // 1. 定义用户结构体（相当于数据库里的一行）
// typedef struct {
//     char username[MAX_LEN];
//     char password[MAX_LEN];
// } User;

// // 全局变量：用来模拟“数据库”
// User userDB[MAX_USERS];   // 这是一个数组，用来存所有注册的用户
// int userCount = 0;        // 记录当前系统中已经有多少个用户

// // 函数声明
// void registerUser();
// int loginUser();
// void clearInputBuffer();

// int main() {
//     int choice;
    
//     while (1) {
//         printf("\n===== 欢迎使用账号系统 =====\n");
//         printf("1. 注册 (Register)\n");
//         printf("2. 登录 (Login)\n");
//         printf("3. 退出 (Exit)\n");
//         printf("请输入选项: ");
//         scanf("%d", &choice);
//         clearInputBuffer(); // 清理输入缓存，防止影响后续字符串读取

//         switch (choice) {
//             case 1:
//                 registerUser();
//                 break;
//             case 2:
//                 if (loginUser()) {
//                     printf(">>> 登录成功！欢迎回来！\n");
//                 } else {
//                     printf(">>> 登录失败：用户名或密码错误！\n");
//                 }
//                 break;
//             case 3:
//                 printf("退出系统。\n");
//                 exit(0);
//             default:
//                 printf("无效选项，请重新输入。\n");
//         }
//     }
//     return 0;
// }

// // 清理输入缓冲区
// // 作用：因为 scanf 读数字后，回车换行符(\n)会留在缓冲区里，
// // 如果不清掉，后面的 fgets 会直接读到一个空行。
// void clearInputBuffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }

// // 注册功能
// void registerUser() {
//     // 检查系统是否已满
//     if (userCount >= MAX_USERS) {
//         printf("系统用户已满，无法注册！\n");
//         return;
//     }

//     User newUser;

//     // 获取用户名
//     printf("请输入新用户名: ");
//     // 使用 fgets 比 scanf("%s") 更安全，可以防止缓冲区溢出
//     fgets(newUser.username, MAX_LEN, stdin);
//     // fgets 会把回车符也读进去，我们需要把它替换成字符串结束符 '\0'
//     newUser.username[strcspn(newUser.username, "\n")] = 0;

//     // 【关键逻辑】检查用户名是否已存在
//     for (int i = 0; i < userCount; i++) {
//         // strcmp 比较两个字符串，如果完全一样会返回 0
//         if (strcmp(userDB[i].username, newUser.username) == 0) {
//             printf("注册失败：该用户名已被占用！\n");
//             return;
//         }
//     }

//     // 获取密码
//     printf("请输入密码: ");
//     fgets(newUser.password, MAX_LEN, stdin);
//     newUser.password[strcspn(newUser.password, "\n")] = 0;

//     // 将新用户存入“数据库”数组
//     // 注意：这里直接存了明文密码（仅供学习，实际开发必须加密）
//     userDB[userCount] = newUser;
//     userCount++; // 用户总数加 1

//     printf("注册成功！请返回主菜单登录。\n");
// }

// // 登录功能
// // 返回值：1 代表登录成功，0 代表失败
// int loginUser() {
//     char inputUsername[MAX_LEN];
//     char inputPassword[MAX_LEN];

//     // 获取输入的账号
//     printf("请输入用户名: ");
//     fgets(inputUsername, MAX_LEN, stdin);
//     inputUsername[strcspn(inputUsername, "\n")] = 0;

//     // 获取输入的密码
//     printf("请输入密码: ");
//     fgets(inputPassword, MAX_LEN, stdin);
//     inputPassword[strcspn(inputPassword, "\n")] = 0;

//     // 【关键逻辑】遍历整个“数据库”寻找匹配的用户
//     for (int i = 0; i < userCount; i++) {
//         // 判断用户名是否匹配
//         if (strcmp(userDB[i].username, inputUsername) == 0) {
//             // 用户名匹配，再判断密码是否匹配
//             if (strcmp(userDB[i].password, inputPassword) == 0) {
//                 return 1; // 账号密码都匹配，成功
//             } else {
//                 return 0; // 账号对，密码错
//             }
//         }
//     }

//     return 0; // 找了一圈，没找到这个用户名
// }


#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);          // 获取当前时间戳
    if (now == (time_t)-1) {
        perror("time");
        return 1;
    }

    struct tm *local = localtime(&now); // 转为本地时间
    if (local == NULL) {
        perror("localtime");
        return 1;
    }

    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", local);
    printf("当前时间：%s\n", buf);

    return 0;
}