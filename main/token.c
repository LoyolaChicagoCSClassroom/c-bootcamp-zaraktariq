// token.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"  // Include the token header file

// Function to remove spaces from input
char *generateSpaceless(char *input) {
    return strtok(input, " ");
}

// Function to create a token based on input
TOKEN parseToken(char *token) {
    TOKEN returnToken;

    // Determine the type of token
    if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
        returnToken.type = OPERATOR;
    } else if (*token == ':' || *token == ';') {
        returnToken.type = SYMBOL;
    } else if (isdigit(*token)) {
        returnToken.type = NUMBER;
    } else if (strcmp(token, "EOF") == 0) {
        returnToken.type = END_OF_FILE;
    } else {
        returnToken.type = WORD;
    }

    // Set the text of the token
    returnToken.text = strdup(token);

    return returnToken;
}

// Function to convert token type to string
const char *tokenTypeToString(enum token_type_t type) {
    switch (type) {
        case NUMBER:
            return "Number";
        case OPERATOR:
            return "Operator";
        case SYMBOL:
            return "Symbol";
        case WORD:
            return "Word";
        case END_OF_FILE:
            return "EndOfFile";
        default:
            return "Unknown";
    }
}