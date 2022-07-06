#include "llist.h"

lin *makenode(char *element)
{
    lin *cnode = (lin *)malloc(sizeof(lin));
    assert(cnode != NULL);
    strcpy(cnode->element, element);
    cnode->node = NULL;
    return cnode;
}

void insert_node(lin *cnode, char *number, int *count) //count keeps track of the last element added

{
    lin *tnode;
    tnode = makenode(number);
    tnode->node = cnode->node;
    cnode->node = tnode;
    (*count)++;
}
int find_element(char *X, lin *tnode, int count)
{
    int index = count - 1;
    for (lin *temp = tnode->node; temp != NULL; temp = temp->node)
    {
        if (strcmp(temp->element, X) == 0)
        {
            return index;
        }
        index--;
    }
    return -1;
}
