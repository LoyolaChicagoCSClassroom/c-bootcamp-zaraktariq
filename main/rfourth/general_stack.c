#include "general_stack.h"

#include <stdlib.h>
#include <stdio.h>

void general_stack_init(general_stack_t *stk, int capacity)
{
    SLIST_INIT(&stk->head2);
    stk->size = 0;
    stk->capacity = capacity;
}

int general_stack_push(general_stack_t *stk, char* value)
{
    if (stk->size >= stk->capacity)
    {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    general_entry_t *newEntry = malloc(sizeof(general_entry_t));
    if (newEntry)
    {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head2, newEntry, entries);
        stk->size++;
        return 1; // success
    }
    return 0; // fail
}

int general_stack_pop(general_stack_t *stk, char* top_value)
{
    general_entry_t *entry = SLIST_FIRST(&stk->head2);
    if (entry)
    {
        char* value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head2, entries);
        free(entry);
        stk->size--;
        top_value = value;
        return 1; // success
    }
    return 0; // fail
}

void general_stack_declare_variable(general_stack_t *stk)
{
    general_stack_push(stk,"variable");
}
