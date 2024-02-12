// main.c
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main (int argc, char **argv) {
    // ensure user calls the program correctly 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *input = argv[1];

    // Process tokens from input
    struct token_t current_token;
    while ((current_token = get_next_token(&input)).type != END_OF_FILE) {
        // Print token information
        printf("Token Class: %s, Text: %s\n", token_type_to_string(current_token.type), current_token.text);
    }

    return 0;
}