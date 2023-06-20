#include "monty.h"

void push(stack_tm **stac, int va)
{
    stack_tm *new_node = malloc(sizeof(stack_tm));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->x = va;
    new_node->pr = NULL;
    new_node->nextone = *stac;

    if (*stac != NULL)
        (*stac)->pr = new_node;

    *stac = new_node;
}

