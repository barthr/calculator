#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL] = {0};

// Pop a value from te stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("error: stack empty\n");
    return 0.0;
}

// Push a value to the stack
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, cant push %g\n", f);
    }
}

void swap(void)
{
    if (sp >= 2)
    {
        double val1 = pop();
        double val2 = pop();
        push(val1);
        push(val2);
    }
}

void duplicate(void)
{
    if (sp >= 1)
    {
        double dupl = pop();
        push(dupl);
        push(dupl);
    }
}

void print_top_elem(void)
{
    if (sp > 0)
    {
        printf("Top element => %lf\n", val[sp - 1]);
    }
}

void clear(void)
{
    memset(val, 0, MAXVAL * sizeof(double));
    sp = 0;
}