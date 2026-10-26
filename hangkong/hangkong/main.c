#include <stdio.h>
#include "user/index.c"


int main(int argc, char *argv[]) {
    userList = createUserList();
    insertUserListAfter(createUserNode("zhangSan", "1212", "1122", USER));
    insertUserListAfter(createUserNode("liSi", "111222", "11223344", USER));
    insertUserListAfter(createUserNode("admin", "123124", "112233", ADMIN));
}
