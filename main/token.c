// token.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

// Function to remove spaces from input
char *generateSpaceless(const char *input) {
    return strtok(input, " ");
}

// Function to create a token based on input
TOKEN parseToken(const char *token_str) {
    TOKEN returnToken;

    // Determine the type of token
    if (isdigit(token_str[0]) || (token_str[0] == '-' && isdigit(token_str[1]))) {
        returnToken.type = NUMBER;
    } else if (strcmp(token_str, "+") == 0 || strcmp(token_str, "-") == 0 ||
               strcmp(token_str, "*") == 0 || strcmp(token_str, "/") == 0) {
        returnToken.type = OPERATOR;
    } else if (strcmp(token_str, ":") == 0 || strcmp(token_str, ";") == 0) {
        returnToken.type = SYMBOL;
    } else {
        returnToken.type = WORD;
    }

    // Set the text of the token
    returnToken.text = strdup(token_str);

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
        case INVALID:
            return "Invalid";
        default:
            return "Unknown";
    }
}
