#include <stdio.h>
#include <string.h>
// struct student {
//         char name[10];
//         int age;
//         float score;
//     };
// int main()
// {
//     struct student s1;
//     strcpy(s1.name, "nick");
//     s1.age = 24;
//     s1.score = 75;
//     printf("%s, %d, %.2f\n", s1.name, s1.age, s1.score);

//     struct student s2 = {"mark", 47, 53};
//     printf("%s, %d, %.2f\n", s2.name, s2.age, s2.score);
//     printf("%d", sizeof(s1));
// }

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    // printf("%d", len);
    for (int i = 1; i < len; i++)
    {
        int base = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > base)
        {
            arr[j + 1] = arr[j];           
            j--;
        }
        arr[j+1] = base;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}

// int main()
// {
//     int arr[5] = {5, 3, 1, 7, 2};
//     int len = sizeof(arr)/sizeof(arr[0]);
//     // printf("%d", len);
//     for (int i = 1; i < len; i++)
//     {
//         for(int j = 0; j<5-i; j++)
//         {
//             if(arr[j+1]<arr[j])
//             {
//                 int base = arr[j+1];
//                 arr[j+1] = arr[j];
//                 arr[j] = base;
//             }
//         }

//     }
//     for (int i = 0; i < len; i++)
//         {
//             printf("%d\n", arr[i]);
//         }
//     return 0;
// }