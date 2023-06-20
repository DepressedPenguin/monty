#include "monty.h"

void pall(stack_tm **stac)
{
    stack_tm *cu = *stac;

    while (cu != NULL)
    {
        printf("%d\n", cu->x);
        cu = cu->nextone;
    }
}

