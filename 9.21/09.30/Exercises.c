// #include<stdio.h>
// int main()
// {
//     int num[10] = {11,22,33,44,55,66,77,88,99,98};
//     for(int i = 0; i<10; i++)
//     {
//         printf("i = %d  num[%d] = %d\n", i, i, num[i]);
//     }
//     return 0;
// }


// #include<stdio.h>
// int main()
// {

//     int count = 0;
//     int arr1[10] = {0};
//     while(count<10){
        
//         scanf("%d",&arr1[count++]);
//     }



//     // int arr2[5] = {11,22,33,44,55};
//     int max = arr1[0];
//     int min = arr1[0];
//     for(int i = 0; i<5; i++)
//     {
//         if(arr1[i]<min)
//         {
//             min = arr1[i];
//         }
//         if(arr1[i]>max)
//         {
//             max = arr1[i];
//         }   
//     }
//     printf("min=%d max=%d min+max=%d", min, max, min+max);
//     return 0;
// }


#include <stdio.h>

int main() {
    char input;
    int i, j, total_rows;
    char ch;

    // 1. 接收用户输入
    printf("请输入一个大写字母: ");
    scanf("%c", &input);

    // 2. 计算总行数 (例如输入E，'E'-'A'+1 = 5行)
    total_rows = input - 'A' + 1;

    // 3. 外层循环控制行数
    for (i = 0; i < total_rows; i++) {
        
        // 4. 内层循环 1：打印前导空格
        // 空格数量 = 总行数 - 1 - 当前行号
        for (j = 0; j < total_rows - 1 - i; j++) {
            printf(" ");
        }

        // 5. 内层循环 2：打印左侧升序字母
        // 从 'A' 开始，一直打印到 'A' + 当前行号
        for (ch = 'A'; ch <= 'A' + i; ch++) {
            printf("%c", ch);
        }

        // 6. 内层循环 3：打印右侧降序字母
        // 从 'A' + 当前行号 - 1 开始，递减打印到 'A'
        // 注意：第一行时 i=0，'A'-1 不满足 >= 'A'，循环自动不执行，正好符合第一行没有右侧字母的要求
        for (ch = 'A' + i - 1; ch >= 'A'; ch--) {
            printf("%c", ch);
        }

        // 7. 打印完一行后换行
        printf("\n");
    }

    return 0;
}