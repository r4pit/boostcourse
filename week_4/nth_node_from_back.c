#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int count = 0;

void append(node *head, int data)
{
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    count++;

    node *tmp = malloc(sizeof(node));
    tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = n;

}

int get_last_node (node *head, int k)
{
    // todo (뒤에서 k번째)
    for (int i=0; i < (count - k); i++)
    {
        if (head->next->next == NULL)
            return -9999;

        head = head->next;
    }
    return head->next->data;
}

void print_list (node *head)
{
    //todo
    while (head->next != NULL)
    {
        printf("%d ", head->next->data);
        head = head->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    node *head = malloc(sizeof(node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    print_list(head);
    int number = 1;
    printf("\n%dth last node is %d\n", number, get_last_node(head, number));
}