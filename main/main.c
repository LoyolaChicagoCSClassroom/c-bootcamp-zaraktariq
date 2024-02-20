// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

void tester(const char *testCase, const char *expectedType, const char *expectedText);

int main() {
    // Test cases for different token types
    char *testWord = "hello";
    tester(testWord, "Word", "hello");

    char *testNum = "1";
    tester(testNum, "Number", "1");

    char *testOp = "+";
    tester(testOp, "Operator", "+");

    char *testSym = ";";
    tester(testSym, "Symbol", ";");

    // Additional test case
    char *testInvalid = "invalid123";
    tester(testInvalid, "Invalid", "invalid123");

    // Interactive tokenization from stdin
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1) {
        char *token_str = strtok(line, " \t\n");

        while (token_str != NULL) {
            TOKEN token = parseToken(token_str);
            printf("Token: Type=%s, Text=%s\n", tokenTypeToString(token.type), token.text);
            free(token.text);
            token_str = strtok(NULL, " \t\n");
        }
    }

    // Free allocated memory
    free(line);

    return EXIT_SUCCESS;
}

void tester(const char *testCase, const char *expectedType, const char *expectedText) {
    char *token = generateSpaceless(testCase);

    while (token != NULL) {
        TOKEN returnToken = parseToken(token);
        printf((strcmp(tokenTypeToString(returnToken.type), expectedType) == 0 &&
                strcmp(returnToken.text, expected
