#include<stdio.h>
#include <string.h>
int main()
{
    char str1[10]={'k'};
    char str2[10]="hellozou";
    printf("%c\n", str1[0]);
    printf("%s\n", strcpy(str1, str2));
    printf("%s\n", str1); 
 
    return 0;
}