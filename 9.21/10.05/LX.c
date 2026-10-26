#include <stdio.h>
int main()
{
    // int y=10;
    // for(; y>0; y--)
    // {
    //     if(y%3==0){
    //     printf("%d", --y);
    //     continue;
    // }
    // }

    // while(y--);
    // printf("y=%d", y);

    int i;
    for (i = 0; i <3; i++)
    
        switch (i)
        {
            case 1:printf("%d", i);
            case 2:printf("%d", i);
            default :printf("%d", i);
            
        }
    
    
    return 0;
}