/* op_push.c */

#include "monty.h"

void push(stack_t **stac, int va)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = va;
    new_node->prev = NULL;
    new_node->next = *stac;

    if (*stac != NULL)
        (*stac)->prev = new_node;

    *stac = new_node;
}

