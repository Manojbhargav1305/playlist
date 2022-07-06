#include"stack.h"

void push(stack *alpha, char *data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    strcpy(temp->data, data);
    temp->next = NULL;
    alpha = temp;
}
char *pop(stack *alpha)
{
    char *ans = (char *)calloc(10000, sizeof(char));
    if (alpha != NULL)
    {
        stack *temp = alpha;
        strcpy(ans, alpha->data);
        alpha = alpha->next;
        free(temp);
    }
    return ans;
}