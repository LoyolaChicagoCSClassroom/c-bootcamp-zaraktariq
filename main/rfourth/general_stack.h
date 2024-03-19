#ifndef GENERAL_STACK_H
#define GENERAL_STACK_H

#include <stdio.h>
#include <sys/queue.h>

typedef struct general_entry
{
    char* value;
    SLIST_ENTRY(general_entry)
    entries;
} general_entry_t;

typedef struct general_stack
{
    SLIST_HEAD(stackhead2, general_entry) head2;
    int size; 
    int capacity;
} general_stack_t;

extern void general_stack_init(general_stack_t *stk, int capacity);
extern void general_stack_declare_variable(general_stack_t *stk);
extern int general_stack_push(general_stack_t *stk, char* value);
extern int general_stack_pop(general_stack_t *stk, char* top_value);

#endif // INT_STACK_H
