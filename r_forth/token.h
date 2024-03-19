// token.h
#ifndef TOKEN_H
#define TOKEN_H

// Enumeration to represent different token types
enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    VARIABLE,
    INVALID
};

// Structure to represent a token
typedef struct token_t {
    enum token_type_t type;
    char *text;
} TOKEN;

// Function prototypes
TOKEN parseTokens(char *token);

char *resolveToString(enum token_type_t type_t);

char *generateSpaceless(char *input);

char *resolveArithOp(char *symbol);

#endif // TOKEN_H
