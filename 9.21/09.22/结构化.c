#include <stdio.h>


    struct Person
    {
        char name[32];
        int age;
        int score;
};


int main()
{
//结构化
    // struct Person A = {"mark", 22, 77};
    // struct Person B = {"mork", 12, 78};

    // printf("%s %d %d\n",A.name, A.age, A.score);
    // printf("%s %d %d\n",B.name, B.age, B.score);
    
    // printf("%d\n", sizeof(A));
    // printf("%p %p\n", &A, &A+1);
    struct Person students[5] = {
        {"mark", 12, 77}, {"jim", 22, 75}, {"tom", 42, 57}, {"merry", 32, 67}, {"jork", 25, 79}
    };
    for(int i = 0; i<5; i++)
    {
        printf("%s %d %d\n", students[i].name, students[i].age, students[i].score);
    }
    printf("%d\n", sizeof(students));

return 0;
}

