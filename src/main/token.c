// token.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

char *generateSpaceless(char *input) {
    return strtok(input, " ");
}

    // create token
TOKEN parseToken(char *token) {
    TOKEN returnToken;

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

    returnToken.text = strdup(token);

    return returnToken;
}

const char *token_type_to_string(enum token_type_t type) {
    if (type == NUMBER) {
        return "Number";
    } else if (type == OPERATOR) {
        return "Operator:";
    } else if (type == SYMBOL) {
        return "Symbol";
    } else if (type == WORD) {
        return "Word";
    } else if (type == END_OF_FILE) {
        return "EndOfFile";
    } else {
        return "Unknown";
    }
}
