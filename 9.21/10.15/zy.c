
// 使用递归函数实现十进制转换二进制
//  #include <stdio.h>
//  void func(int n)
//  {
//      if (n == 0)
//      {
//          return;
//      }
//      // printf("func start n=%d\n", n); // 递推过程
//      func(n / 2);
//      printf("%d", n % 2); // 回归过程
//  }
//  int main()
//  {
//      func(100);
//      return 0;
//  }

// 字符串逆序输出
#include <stdio.h>

void func(char *n)
{
    if (*n == '\0')
    {
        return ;
    }
    func(n + 1);
    printf("%c", *n);
}
int main()
{
    char arr[] = "abcdefghi";
    func(arr);
}
