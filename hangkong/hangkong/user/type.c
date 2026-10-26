// 权限
enum permission {
    ADMIN = 1,
    USER,
};


// // 状态
// enum status {
//     DEACTIVATE,
//     NORMAL
// };

// 用户链表
typedef struct userTypeList {
    char *userName;
    char *password;
    char *IDCode;
    enum permission permission;
    struct userTypeList *prev;
    struct userTypeList *next;
} userTypeList;
