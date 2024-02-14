// token.h
#ifndef TOKEN_H
#define TOKEN_H

// Enumeration to represent different token types
enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    END_OF_FILE
};

// Structure to represent a token
typedef struct token_t {
    enum token_type_t type;
    char *text;
} TOKEN;

// Function prototypes
char *generateSpaceless(char *input);
TOKEN parseToken(char *token);
const char *tokenTypeToString(enum token_type_t type);

#endif // TOKEN_H