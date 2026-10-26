// #include <stdio.h>
// int main()
// {
//     int i = 1;
//     int n = 0;
//     do{
        
//         n += i;
//         i++;
//     } while (i <= 100);
//     printf("%d", n);
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int n = 0;
//     while(i <= 100)
//     {
//         n += i;
//         i++;
//     }
//     printf("%d", n);
//     return 0;
// }


#include <stdio.h>
int main()
{
    int n = 0;
    for(int i = 0; i <= 100; i++)
    {
        n += i;
        
    }
    printf("%d", n);
    return 0;
}