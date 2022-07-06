#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct _lin
{
    char element[10000];
    struct _lin *node;
}lin;

lin *makenode(char *element);
void insert_node(lin *cnode, char *number, int *count);
int find_element(char *X, lin *tnode, int count);