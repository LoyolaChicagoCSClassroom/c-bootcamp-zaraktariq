// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

int main(int argc, char *argv[])
{
    char *token = generateSpaceless(argv[1]);
    
    while(token != NULL) 
    {
        TOKEN returnToken = parseToken(token);
        printf("CLASS: %s, TEXT: %s\n",resolveToString(returnToken.type),returnToken.text);
        token = strtok(NULL," ");
    }
    return EXIT_SUCCESS;
}