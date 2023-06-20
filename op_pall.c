/* op_pall.c */

#include "monty.h"

void pall(stack_t **stac)
{
    stack_t *cu = *stac;

    while (cu != NULL)
    {
        printf("%d\n", cu->n);
        cu = cu->next;
    }
}

