#include "queue.h"
void enqueue(queue *alpha, char data[])
{
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->data, data);
    temp->next = NULL;
    if (alpha->front)
        alpha->front->next = temp;
    alpha->front = temp;
    if (!alpha->back)
        alpha->back = temp;
}
char *deque(queue *alpha)
{
    node *temp = alpha->back;
    char *ans = (char *)calloc(10000, sizeof(char));
    strcpy(ans, temp->data);
    temp = temp->next;
    free(alpha->back);
    if (alpha->back == alpha->front)
        alpha->front = NULL;
    alpha->back = temp;
    return ans;
}
void printqueue(node* qnode)
{
    while(qnode!=NULL)
    {
        printf("%s \n",qnode->data);
        qnode=qnode->next;
    }
}