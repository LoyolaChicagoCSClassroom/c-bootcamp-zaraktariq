#ifndef RESOLVEACTIONS_H
#define RESOLVEACTIONS_H

// int_stack_t resolveArith(char *answer, int_stack_t myIntStack);
void resolveArith(char *answer, int_stack_t *myIntStack);

void resolveWord(char *answer, int_stack_t *myIntStack, int textLength);

void resolveSymbol(char *answer, int_stack_t *myIntStack);

void resolveVariable(char *answer, general_stack_t *myGeneralStack, int textLength);

#endif