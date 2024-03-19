#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"
#include "general_stack.h"
#include "resolveActions.h"

int main(int argc, char *argv[])
{
    char *input;
    char buffer[100];
    const int capacity = 100;

    int_stack_t myIntStack;
    general_stack_t myGenStack;
    printf("\nTYPE 'exit' TO EXIT THE PROGRAM\n");

    int_stack_init(&myIntStack, capacity);
    printf(": ");
    fgets(input, sizeof(buffer), stdin);

    char *token = generateSpaceless(input);
    while(strcmp(token, "exit") != 0)  
    {
        while (token != NULL)
        {
            TOKEN returnToken = parseTokens(token);
            const int textLength = strlen(returnToken.text);
            switch (returnToken.type_t)
            { 
            case NUM:
            {
                int value = atoi(returnToken.text);
                int success = int_stack_push(&myIntStack, value);
                if (!success)
                {
                    fprintf(stderr, "Stack overflow: %d\n", value);
                }
                break;
            }

            case ARITH_OP:
                resolveArith(returnToken.text, &myIntStack);
                break;
            case WORD:
                resolveWord(returnToken.text, &myIntStack, textLength);
                break;
            case SYMB:
                resolveSymbol(returnToken.text, &myIntStack);
                break;
            case VAR:
                resolveVariable(returnToken.text, &myGenStack, textLength);
            }
            token = strtok(NULL, " ");
        }
        int_stack_print(&myIntStack, stdout);
        printf(": ");
        fgets(input, sizeof(buffer), stdin);
        token = generateSpaceless(input);
        
    }

    return EXIT_SUCCESS;
}