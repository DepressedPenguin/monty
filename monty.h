#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structure */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Function Prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack);
void free_stack(stack_t *stack);
void process_file(const char *filename, stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);

#endif /* MONTY_H */

