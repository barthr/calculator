#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main(void)
{
    int type;
    char s[MAXOP];
    double op2;
    double variable;
    double recent_value;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case IDENTIFIER:
            handle_function(s);
            break;
        case ASSIGNMENT:
            push(handle_variable(s));
            break;
        case VARIABLE:
            variable = get_variable(s);
            if (variable != -1)
                printf("\t%f\n", variable);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: divide by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: divide by zero\n");
            break;
        case '\n':
            recent_value = pop();
            sprintf(s, "r=%f", recent_value);
            push(handle_variable(s));
            printf("Result =>\t%f\n", recent_value);
            break;
        default:
            printf("Unknown command %s\n", s);
            break;
        }
    }
}
