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
    struct token_t token;

    if (isdigit(token_str[0])) {
        token.type = NUMBER;
    } else if (strcmp(token_str, "+") == 0 || strcmp(token_str, "-") == 0 || strcmp(token_str, "*") == 0|| strcmp(token_str, "/") == 0 ) {
        token.type = OPERATOR;
    } else if (strcmp(token_str, ";") == 0 || strcmp(token_str, ":") == 0) {
        token.type = SYMBOL;
    } else {
        token.type = WORD;
    }
    
    /*The strdup function is a standard C library function that stands for "string duplicate."
    It takes a string (token_str in this case) as an argument, allocates memory for a new string of the same length, 
    and copies the content of the original string into the new one. 
    The result is a pointer to the newly allocated string.*/
    token.text = strdup(token_str);

    return token;
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
