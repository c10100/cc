#include <stdio.h>
int main()
{
    char str[32] = "google";
    char arr[] = {0};
    int i, j, count;
    
    
    count = 0;
    // printf("%d", str[9]);
    for (int i = 0; i < 32; i++)
    {
        int n = 0;
        for (int j = 0; j < count; j++)
        {
            if (str[i] == arr[j])
            {
                n = 1;
                break;
            }
        }
        if (n == 0)
        {
            arr[count]=str[i];
            count++;
        }
    }
    printf("%s", arr);
    return 0;
}