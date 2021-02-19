#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *array;
    int top;
}
stack;

void pop(stack *stack, char *output, int *index)
{
    stack->top--;
    output[++*index] = stack->array[stack->top +1];
    stack->array[stack->top +1] = 0;
}

int main(void)
{
    char input[1000] = {0,};
    char output[1000] = {0,};
    scanf("%s", input);

    stack *stack = malloc(sizeof(stack));
    stack->top = -1;
    stack->array = malloc(sizeof(char)*100);

    int index = -1;
    for (int i=0,n=strlen(input); i<n; i++)
    {
        if(input[i] == '(')
        {
            stack->array[++stack->top] = input[i];
        }   
        else if(input[i] == '*' || input[i] == '/')
        {
            stack->array[++stack->top] = input[i];
        }
        else if(input[i] == '+' || input[i] == '-')
        {
            while(1)
            {
                if (stack->array[stack->top] != '*' && stack->array[stack->top] != '/')
                    break;
                pop(stack, output, &index);
            }
            stack->array[++stack->top] = input[i];
        }
        else if(input[i] == ')')
        {
            while(stack->array[stack->top] != '(')
            {
                pop(stack, output, &index);
            }
            stack->top--;
            stack->array[stack->top +1] = 0;
        }
        else
        {
            output[++index] = input[i];
        }
    }
    for (int j=0; stack->top != -1; j++)
    {
        pop(stack, output, &index);
    }
    printf("%s\n", output);
}