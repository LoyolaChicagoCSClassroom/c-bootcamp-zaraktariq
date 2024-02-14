// token.h
#ifndef TOKEN_H
#define TOKEN_H

enum token_type_t {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    END_OF_FILE
};

typedef struct token_t {
    enum token_type_t type;
    char *text;
} TOKEN;

TOKEN parseToken(char *token);

const char *tokenTypeToString(enum token_type_t type);

char *generateSpaceless(char *input);

#endif // TOKEN_H
