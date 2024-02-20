// token.h
#ifndef TOKEN_H
#define TOKEN_H

// Enumeration to represent different token types
enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    INVALID
};

// Structure to represent a token
typedef struct token_t {
    enum token_type_t type;
    char *text;
} TOKEN;

// Function prototypes
char *generateSpaceless(const char *input);
TOKEN parseToken(const char *token);
const char *tokenTypeToString(enum token_type_t type);

#endif // TOKEN_H
