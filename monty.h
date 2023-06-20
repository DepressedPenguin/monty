#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structure*/
typedef struct stack_tm
{
    int x;
    struct stack_tm *pr;
    struct stack_tm *nextone;
} stack_tm;

/* Prototypes */
void push(stack_tm **stac, int va);
void pall(stack_tm **stac);

#endif /* MONTY_H */
