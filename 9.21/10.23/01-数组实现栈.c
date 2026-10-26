#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 栈结构体
typedef struct
{
    int capacity; // 栈容量
    int top;      // 栈顶索引
    int *data;    // 栈数据数组
} Stack_t, *Stack_p;

// 初始化栈
Stack_p stack_init(int capacity)
{
    Stack_p stack = (Stack_p)malloc(sizeof(Stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int *)malloc(capacity * sizeof(int));
    memset(stack->data, 0, capacity * sizeof(int)); // 初始化数组为0
    return stack;
}
// 判断栈是否为空
int stack_empty(Stack_p stack)
{
    return stack->top == -1;
}

// 判断栈是否满
int stack_full(Stack_p stack)
{
    return stack->top == stack->capacity - 1;
}

// 栈不需要遍历 调试写一个遍历
void stack_print(Stack_p stack)
{
    printf("Stack Capacity: %d size: %d Stack: ", stack->capacity, stack->top + 1); // 栈顶索引

    if (stack_empty(stack))
    {
        printf("Empty\n");
        return;
    }

    for (int i = 0; i < stack->capacity; i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// 入栈
void stack_push(Stack_p stack, int value)
{
    if (stack_full(stack))
    {
        printf("Stack is full\n");
        return;
    }

    stack->data[stack->top + 1] = value;
    stack->top++;
}

// 出栈
void stack_pop(Stack_p stack)
{
    if (stack_empty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    stack->data[stack->top] = 0;
    stack->top--;
}

// 访问栈顶元素
int stack_top(Stack_p stack)
{
    return stack->data[stack->top];
}

int main()
{

    Stack_p stack = stack_init(5);
    stack_print(stack);

    stack_push(stack, 11);
    stack_print(stack);

    stack_push(stack, 22);
    stack_print(stack);

    stack_push(stack, 33);
    stack_print(stack);

    stack_push(stack, 44);
    stack_print(stack);

    stack_push(stack, 55);
    stack_print(stack);

    stack_push(stack, 66);
    stack_print(stack);

    printf("------------------\n");
    stack_pop(stack);
    stack_print(stack);

    stack_pop(stack);
    stack_print(stack);

    stack_pop(stack);
    stack_print(stack);

    stack_pop(stack);
    stack_print(stack);
}