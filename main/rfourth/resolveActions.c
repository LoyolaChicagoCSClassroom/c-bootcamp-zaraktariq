#include "int_stack.h"
#include "general_stack.h"
#include "token.h"
#include <string.h>
#include <stdlib.h>

void resolveArith(char *answer, int_stack_t *mis)
{
    switch (*answer)
    { 
    case '+':
        int_stack_add(mis);
        break;
    case '-':;
        int_stack_subtract(mis);
        break;
    case '*':
        int_stack_multiply(mis);
        break;
    case '/':
        int_stack_divide(mis);
        break;
    }
}

void resolveWord(char *answer, int_stack_t *mis, int textLength)
{

    char text[textLength+1];
    strncpy(text, answer, textLength);
    text[textLength-1] = '\0';

    if (strcmp(text, "rot") == 0)
    {
        int_stack_rot(mis);
    }
    else if (strcmp(text, "dup") == 0)
    {
        int_stack_dup(mis);
    }
    else if (strcmp(text, "swap") == 0)
    {
        int_stack_swap(mis);
    }
    else if (strcmp(text, "drop") == 0)
    {
        int_stack_drop(mis);
    }
    else if (strcmp(text, "over") == 0)
    {
        int_stack_over(mis);
    }
    else if(strcmp(text, "exit") == 0)
    {
        exit(0);
    }
}

void resolveVariable(char *answer, general_stack_t *mgs, int textLength)
{ 
    char text[textLength + 1];
    strncpy(text, answer, textLength);
    text[textLength-1] = '\0';

    if (strcmp(text, "variable") == 0)
    {
        general_stack_declare_variable(mgs);
    }
}

void resolveSymbol(char *answer, int_stack_t *mis)
{
    switch(*answer)
    {
        case '.':
        {
            int top_value;
            int_stack_pop(mis, &top_value);
            break;
        }
        case '<':
            int_stack_less_than(mis);
            break;
        case '>':
            int_stack_greater_than(mis);
            break;
        case '=':
            int_stack_equals(mis);
            break;
    }
}