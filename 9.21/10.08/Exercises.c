// #include<stdio.h>
// int main()
// {
//     int arr[10] = {1,2,3,4,5,};
//     for(int i=0; i<10; i++)
//     {
//         printf("%d\n", arr[i]);
//     }
//     return 0;
// }



#include<stdio.h>
int main()
{
    // int num = 100;
    // int *p = &num;
    // *p=200;
    // printf("%d\n%p", num, p);
    // int k,j,s;
    // for(k=2; k<6; k++,k++)
    // {
    //     s=1;
    //     for(j=k; j<6; j++)
    //     {
    //         s+=j;
    //     }

    // }
    // printf("%3d\n", s);

    int arr[3][4] = {4,4,34,37,3,12,2,6,5,17,9,11};
    int sum=0;
    int min=arr[0][0];
    int a=0,b=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            sum+=arr[i][j];
            if(arr[i][j]<min)
            {
                min=arr[i][j];
                a=i;b=j;
            }
        }
    }
    printf("sum=%d\nmin=%d\n下标:%d,%d", sum, min,a,b);
    return 0;
}