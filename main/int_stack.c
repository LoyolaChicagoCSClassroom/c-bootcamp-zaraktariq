// int_stack.c

#include "int_stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void int_stack_init(int_stack_t *stk, int capacity)
{
    SLIST_INIT(&stk->head);
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value)
{
    if (stk->size >= stk->capacity)
    {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    int_entry_t *newEntry = malloc(sizeof(int_entry_t));
    if (newEntry)
    {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head, newEntry, entries);
        stk->size++;
        return 1; // success
    }
    return 0; // fail
    
}

int int_stack_pop(int_stack_t *stk, int *top_value)
{
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry)
    {
        int value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
        stk->size--;
        *top_value = value;
        return 1; // success
    }
    return 0; // fail
}

int int_stack_top(int_stack_t *stk, int *top_value)
{
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry)
    {
        *top_value = entry->value;
        return 1; // success
    }
    return 0; // fail
}

/* Functions for FORTH langauge stack operators */

int int_stack_dup(int_stack_t *stk)
{
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_swap(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

int int_stack_drop(int_stack_t *stk)
{
    if (stk->size < 0)
        return 0;
    int top_value;
    return int_stack_pop(stk, &top_value);
}

int int_stack_over(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value);
}
 
int int_stack_rot(int_stack_t *stk)
{
    if (stk->size < 3)
        return 0;
    int top_value, next_to_top_value, tertiary_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_pop(stk, &tertiary_value);

    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, tertiary_value);
}

int int_stack_2swap(int_stack_t *stk)
{
    if (stk->size < 4)
        return 0;
    int top_first_pair, next_first_pair, top_second_pair, next_second_pair;
    int_stack_pop(stk, &top_first_pair);
    int_stack_pop(stk, &next_first_pair);
    int_stack_pop(stk, &top_second_pair);
    int_stack_pop(stk, &next_second_pair);

    int_stack_push(stk, next_first_pair);
    int_stack_push(stk, top_first_pair);
    int_stack_push(stk, next_second_pair);
    return int_stack_push(stk, top_second_pair);
}

int int_stack_2dup(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    for (int x = 0; x < 2; x++)
    {
        int_stack_push(stk, next_to_top_value);
        int_stack_push(stk, top_value);
    }
    return 1;
}

int int_stack_2over(int_stack_t *stk)
{
    if (stk->size < 4)
        return 0;
    int top_first_pair, next_first_pair, top_second_pair, next_second_pair;
    int_stack_pop(stk, &top_first_pair);
    int_stack_pop(stk, &next_first_pair);
    int_stack_pop(stk, &top_second_pair);
    int_stack_pop(stk, &next_second_pair);

    int_stack_push(stk, next_second_pair);
    int_stack_push(stk, top_second_pair);

    int_stack_push(stk, next_first_pair);
    int_stack_push(stk, top_first_pair);

    int_stack_push(stk, next_second_pair);
    return int_stack_push(stk, top_second_pair);
}

int int_stack_2drop(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    return int_stack_pop(stk, &next_to_top_value);
}

/* Example of how to create a binary operator that works o top two elements (if present) */

int int_stack_add(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

int int_stack_subtract(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value - top_value);
}

int int_stack_multiply(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value * top_value);
}

int int_stack_divide(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value / top_value);
}

int int_stack_equals(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    if (top_value == next_to_top_value)
    {
        return int_stack_push(stk, -1);
    }
    return int_stack_push(stk, 0);
}

int int_stack_less_than(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    if (top_value > next_to_top_value)
    {
        return int_stack_push(stk, -1);
    }
    return int_stack_push(stk, 0);
}

int int_stack_greater_than(int_stack_t *stk)
{
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    if (top_value < next_to_top_value)
    {
        return int_stack_push(stk, -1);
    }
    return int_stack_push(stk, 0);
}

void int_stack_print(int_stack_t *stk, FILE *file)
{
    fprintf(file, "\n\tSTACK\n\t|");
    int_entry_t *entry;
    int length = stk->size;
    if (stk->size == 0)
    {
        fprintf(file, "empty stack\n");
    }

    char *elems = (char *)malloc(length * sizeof(char));

    SLIST_FOREACH(entry, &stk->head, entries)
    {
        char str[sizeof(entry->value)];
        sprintf(str, "%d ", entry->value);
        strcat(elems, str);
    }

    char* token = strtok(elems, " \t\n");
    char* tokens[100];

    int count = 0;
    while (token != NULL)
    {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = count - 1; i >= 0; i--)
    {
        fprintf(file, "%s ", tokens[i]);
    }

    fprintf(file, "<- Top|\n\n");
}

int int_stack_size(int_stack_t *stk)
{
    return stk->size;
}

int int_stack_capacity(int_stack_t *stk)
{
    return stk->capacity;
}