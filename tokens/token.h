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

struct token_t {
    enum token_type_t type;
    char *text;
};

// Function declarations
struct token_t get_next_token(char *input);

#endif // TOKEN_H
