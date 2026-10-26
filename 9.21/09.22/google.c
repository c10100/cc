#include <stdio.h>

int main()
{
    char str[32] = {"google"};
    char newstr[32] = {0};
    int k = 0;

    for (int i = 0; i < 32; i++)
    {
        //
        if (str[i] != 0)
        {
            printf("%c\n", str[i]);
        }
        //
        int n = 0;
        for (int j = 0; j < k; j++)
        {
            if (newstr[j] == str[i])
            {
                n = 1;
                break;
            }
        }
        if (n == 0)
        {
            newstr[k] = str[i];
            k++;
        }
    }
    printf("%s", newstr);
    return 0;
}
