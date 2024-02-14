// token.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

struct token_t get_next_token(char **input) {
    // split tokens on whitespace
    char **token_str = stringtoken(*input, " \t\n");

    // consider the EOF
    if (token_str == NULL) {
        // handel the end of the string/token with grace and create a token for its conclusion
        struct token_t end_token = {END_OF_FILE, NULL};
            return end_token;
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
