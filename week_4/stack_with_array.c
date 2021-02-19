#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int capacity;
    int *array;
}
stack;

stack *create_stack(int capacity)
{
    stack *stack = malloc(sizeof(stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity*sizeof(int));
    return stack;
}

int is_full(stack *stack)
{
    return stack->top == stack->capacity-1;
}

int is_empty(stack *stack)
{
    return stack->top == -1;
}

void push(stack *stack, int item)
{
    if (is_full(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(stack *stack)
{
    int tmp;
    stack->top = stack->top -1;
    tmp = stack->array[stack->top +1];
    stack->array[stack->top +1] = 0;
    return tmp;
}

int peek(stack *stack)
{

}

int main(void)
{
    stack *stack = create_stack(100);

    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    push(stack,50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}