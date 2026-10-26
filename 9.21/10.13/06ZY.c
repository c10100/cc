//6、将字符串中的重复字符删除，并输出新字符串。
// 例如： gooogggle ---> 输出 gole
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    char *arr1 = (char*)malloc(10*sizeof(char));
    strcpy(arr1, "gooogggle");
    char *arr2 = (char*)calloc(sizeof(char), 10);
    int i, j, count;
    
    
    count = 0;
    // printf("%d", str[9]);
    for (int i = 0; i < 32; i++)
    {
        int n = 0;
        for (int j = 0; j < count; j++)
        {
            if (arr1[i] == arr2[j])
            {
                n = 1;
                break;
            }
        }
        if (n == 0)
        {
            arr2[count]=arr1[i];
            count++;
        }
    }
    printf("%s", arr2);

    return 0;
}
