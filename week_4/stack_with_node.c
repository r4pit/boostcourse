#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    int data;
    struct stack_node *next;
}
stack_node;

stack_node *create_stack_node(int data)
{
    stack_node *node = malloc(sizeof(stack_node));
    node->data = data;
    node->next = NULL;
    return node;
}

int is_empty(stack_node *root)
{
    return !root;
}

void push(stack_node **root, int data)
{
    stack_node *n = create_stack_node(data);
    // go to the last node
    stack_node *tmp = malloc(sizeof(stack_node));
    tmp = *root;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
    printf("%d pushed to stack\n", data);
}

int pop(stack_node **root)
{   
    // go to the last node
    stack_node *tmp = malloc(sizeof(stack_node));
    tmp = *root;
    int count = 0;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    int popped = tmp->data;

    // remove the last node
    tmp = *root;
    for (int i=0; i<count-1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;

    return popped;
}

int peek(stack_node *root)
{
    if(is_empty(root))
        return -9999;
    // go to the last node
    stack_node *tmp = malloc(sizeof(stack_node));
    tmp = root;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

void print_list(stack_node* list)
{
    while(list->next != NULL)
    {
        printf("%d ", list->next->data);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    stack_node *root = malloc(sizeof(stack_node));

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);
    printf("\n");
    printf("%d popped from stack\n", pop(&root));
    printf("%d popped from stack\n", pop(&root));
    push(&root, 50);
    printf("%d peeked from stack\n", peek(root));
    printf("%d popped from stack\n", pop(&root));
    printf("%d popped from stack\n", pop(&root));
    printf("%d popped from stack\n", pop(&root));
    return 0;
}