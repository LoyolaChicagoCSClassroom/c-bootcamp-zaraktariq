// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *token = generateSpaceless(argv[1]);

    while (token != NULL) {
        TOKEN returnToken = parseToken(token);
        printf("CLASS: %s, TEXT: %s\n", tokenTypeToString(returnToken.type), returnToken.text);
        token = strtok(NULL, " ");
    }

    // Add an END_OF_FILE token
    TOKEN eofToken = {END_OF_FILE, "EOF"};
    printf("CLASS: %s, TEXT: %s\n", tokenTypeToString(eofToken.type), eofToken.text);

    return EXIT_SUCCESS;
}
