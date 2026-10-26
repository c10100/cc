#include <stdio.h>
//遍历数组
void traverseArray(int *arr, int len, int size)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
}

//判断数组是否满员
void isfull(int len, int size)
{
    return (size == len);
}

//头部插入
void inserthead(int *arr, int len, int size, int a)
{

}

//尾部插入
void inserttail(int *arr, int len, int size, int a)
{
    if(isfull)
    {}
}

int main()
{
    int arr[5] = {11, 22};
    int len = sizeof(arr)/sizeof(arr[0]);
    int size = 2;
    traverseArray(arr, len, size);
    return 0;
}