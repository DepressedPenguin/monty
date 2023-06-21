#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
* swap - Swaps the top two elements
* @stack: Pointer to the top stack
*/
void swap_swap(stack_t **stack)
{
int temp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "Error: can't swap, stack too short\n");
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}

