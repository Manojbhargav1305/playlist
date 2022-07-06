#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct node
{
    struct node *next;
    char data[10000];
} node;
typedef struct queue
{
    node *front;
    node *back;
} queue;

void enqueue(queue *alpha, char data[]);

char *deque(queue *alpha);
void printqueue(node* qnode);

