#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

static double alphabet[ALPHABET_SIZE] = {-1};

int getop(char s[])
{
    int i;
    int c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (isalpha(c))
    {
        i = 0;
        if ((s[++i] = c = getch()) == '=')
        {
            while ((s[++i] = c = getch()))
                if (!isdigit(c) && c != '.')
                    break;
            s[i] = '\0';

            if (c != EOF)
                ungetch(c);
            return ASSIGNMENT;
        }
        else if (c == '\n')
        {
            return VARIABLE;
        }
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return IDENTIFIER;
    }
    else

        if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

void handle_function(char s[])
{
    if (!strcmp(s, "sin"))
        push(sin(pop()));
    else if (!strcmp(s, "exp"))
        push(exp(pop()));
    else if (!strcmp(s, "pow"))
    {
        double temp1 = pop();
        push(pow(pop(), temp1));
    }
    else
        printf("%s is not a supported operation", s);
}

double handle_variable(char s[])
{

    char *dec = &s[2];
    double value = strtod(dec, NULL);

    alphabet[s[0] - 97] = value;
    return value;
}

double get_variable(char s[])
{
    return alphabet[s[0] - 97];
}