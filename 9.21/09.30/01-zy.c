#include <stdio.h>
int main()
{
    printf("输入十个数字：");
    int arr1[10] = {0}; 
    int j = 0;
    
    while(j<10)
    {
        scanf("%d",&arr1[j++]);
    }
    int min = arr1[0];
    int max = arr1[0];
    for (int i = 0; i < 10; i++)
    {
        if(arr1[i]<min)
        {
            min = arr1[i];
        }
        if(arr1[i]>max)
        {
            max = arr1[i];
        } 
    }
    printf("min:%d\nmax:%d\nmin + max=%d\n", min, max, min + max);
    return 0;
}

