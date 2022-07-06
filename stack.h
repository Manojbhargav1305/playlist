#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
typedef struct fun
{
    struct fun *next;
    char data[10000];
} stack;
void push(stack *alpha, char *data);
char *pop(stack *alpha);