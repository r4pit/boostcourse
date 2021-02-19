#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    int front; 
    int rear; 
    int size; 
    int capacity; 
    int *array; 
}
queue;

queue *create_queue(int capacity)
{
    queue *queue = malloc(sizeof(queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity-1;
    queue->size = 0;
    queue->array = malloc((sizeof(int))*queue->capacity);
    return queue;
}

int is_full(queue *queue)
{
    return (queue->size == queue->capacity);
}

int is_empty(queue *queue)
{
    return (queue->size == 0);
}

void enqueue(queue *queue, int item)
{
    if (is_full(queue))
        return;

    queue->array[queue->size] = item;
    queue->rear = queue->array[queue->size];
    queue->size++;

    if (queue->size == 1)
        queue->front = queue->array[0];

    printf("%d enqueued to queue\n", item);
}

int dequeue(queue *queue)
{
    if (is_empty(queue))
        return -9999;
    int item = queue->array[0];
    memmove(queue->array, queue->array+1, sizeof(int)*(queue->size-1));
    queue->size--;
    queue->array[queue->size] = 0;
    queue->front = queue->array[0];

    return item;
}

int main(void)

{
    queue *queue = create_queue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("rear: %d, front: %d\n", queue->rear, queue->front);
    for (int i=0; queue->array[i] != 0; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
    return 0;
}