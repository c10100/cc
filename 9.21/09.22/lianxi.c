// #include <stdio.h>

// int main()
// {
//     // float n1, n2;
//     // printf("请输入两个浮点数\n");
//     // scanf("%f %f", &n1, &n2);
//     // printf("%f*%f = %.2f", n1, n2, n1*n2);

//     // double num1;
//     // scanf("%le", &num1);
//     // printf("%le", num1);
//     // int temp = 1;
//     // char num;

    
//     return 0;
// }
// #include <stdio.h>

// int main()
// {
//     char str[10] = "google";
//     char stt[10] = {0};
//     int k = 0;

//     for(int i = 0; i < 10; i++)
//     {
//         int n = 0;

//         for(int j = 0; j <=k; j++)
//         {
//             if(str[i] == stt[j])
//             {
//                 n = 1;
//                 break;
//             }  
//         }
//         if(n == 0)
//         {
//             stt[k] = str[i];
//             k++;
//             // printf("1");
//         }   
//     }
//     printf("%s\n", stt);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     printf("请输入一个字符");
//     char i;
//     scanf("%c", &i);
//     printf("%c的ASCⅡ码是%d", i, i);
//     return 0;

// }
// #include <stdio.h>
// int main()
// {
//     int a[3] = {1, 2, 3};
//     int *p = a;
//     printf("%d\n", a[0]);
//     printf("%d\n", a[1]);
//     printf("%d\n", *(a));
//     printf("%d\n", *(1+a));
//     printf("%d\n", 1[a]);
// }
#include <stdio.h>
int mian(void)
{
    long a[4] = {1, 2, 3, 4};
    long *p1 = (long *)(&a + 1);
    long *p2 = (long *)((long)a + 1);
    printf("%lx\n", p1[-1]);
    printf("%lx\n", *p2);
    return 0;
}