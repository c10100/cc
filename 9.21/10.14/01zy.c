// 1、研究bzero函数，自定义一个函数实现其功能
#include <string.h>
#include <stdio.h>

// int main()
// {
//     char buf[20] = "hello world";
//     printf("清零前: %s\n", buf);

//     bzero(buf, sizeof(buf));   // 将整个数组清零

//     printf("清零后: %s\n", buf);  // 输出空字符串
//     return 0;

// }

// 2、研究memset函数，自定义一个函数实现其功能，将一段内存全部填入某个值
// int main()
// {
//     char buf[20] = "hello world";
//     printf("%s\n", buf);

//     memset (buf, 'A', sizeof(buf));
//     buf[11] = '\0';
//     printf("%s\n", buf);  
//     return 0;
// }
// 3、研究strcat 函数，自定义一个函数实现其功能，连接俩字符串
// int main()
// {
//     char buf[20] = "hello world";
//     printf("%s\n", buf);
//     char buf1[20] = "hello world";
//     printf("%s", strcat(buf, buf1));

//     return 0;
// }
// 4、研究strstr函数，自定义一个函数实现其功能，查找字符串
// int main()
// {
//     char buf[20] = "hello world";
//     printf("%s\n", buf);
//     // char buf1[20] = "hello world";
//     printf("%s", strstr(buf, "llo"));

//     return 0;
// }
// 5、实现 strlen函数的源码，计算字符串长度
// int main()
// {
//     char buf[20] = "hello world";
//     printf("%d\n", strlen(buf));
// }
// 6、实现 strcmp函数的源码,比较字符串
// int main()
// {
//     char buf[20] = "hello worlD";
//     printf("%s\n", buf);
//     char buf1[20] = "hello woRld";
//     printf("%d", strcmp(buf, buf1));

//     return 0;
// }

// 7、字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的
// 字符串压缩功能。比如，字符串aabcccccaaa会变为2ab5c3a。若“压缩”
// 后的字符串没有变短，则返回原先的字符串。
// 你可以假设字符串中只包含大小写英文字母（a至z）。例:
// 输入：“aabcccccaaa”
// 输出：“2ab5c3a”


int main()
{
    char arr[] = "aabcccccaaa";
    char str[20] = {0}; 
    int len = strlen(arr);
    int count = 1;
    int j = 0;
    for(int i = 1; i<=len; i++)
    {
        if(arr[i]==arr[i- 1])
        {            
            count++;
        }else{
            if(count>1){
            str[j]='0'+count;
            j++;
            }
            str[j]=arr[i-1];
            count=1;
            j++;
            
        }

        
    }
    printf("%s", str);
    return 0;
}
