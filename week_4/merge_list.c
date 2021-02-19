#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
int sales;
struct node *next;
}
node;

node* merge_two_lists(node* list1, node* list2)
{
    node* result = malloc(sizeof(node));
    node* n = result;
    list1 = list1->next;
    list2 = list2->next;

    while (list1 != NULL && list2 != NULL)
    {
        if(list1->sales <= list2->sales)
        {
            n->next = list1;
            list1 = list1->next;
        }
        else
        {
            n->next = list2;
            list2 = list2->next;
        }
        n = n->next;
    }
    
    if (list1 != NULL)
        n->next = list1;
    if (list2 != NULL)
        n->next = list2;
    return result;
}

void append(node* list, int sales)
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    n->next = NULL;
    n->sales = sales;
    
    node* tmp = malloc(sizeof(node));
    tmp = list;
    while(tmp->next != NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = n;
}

void print_list(node* list)
{
    while(list->next != NULL)
    {
        printf("%d ", list->next->sales);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    node* listA = malloc(sizeof(node));
    node* listB = malloc(sizeof(node));

    append(listA,2);
    append(listA,6);
    append(listA,9);
    append(listA,10);

    append(listB,1);
    append(listB,5);
    append(listB,7);
    append(listB,8);
    append(listB,11);

    node* result = merge_two_lists(listA, listB);
    print_list(result);
}
