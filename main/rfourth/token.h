#ifndef TOKEN_H
#define TOKEN_H

struct token_t;

enum token_type_t
{
    NUM,
    ARITH_OP,
    SYMB, 
    WORD,
    VAR
} type_t;

typedef struct token_t
{
    enum token_type_t type_t;
    char *text;
} TOKEN;

TOKEN parseTokens(char *token);

char *resolveToString(enum token_type_t type_t);

char *generateSpaceless(char *input);

char *resolveArithOp(char *symbol);

#endif