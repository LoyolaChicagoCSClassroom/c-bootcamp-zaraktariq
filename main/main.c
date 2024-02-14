// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"  // Include the token header file

// Function prototype for testing tokens
void tester(const char *testCase, const char *expectedType, const char *expectedText);

int main(int argc, char *argv[]) {
    // Test cases for different token types
    char *testWord = "hello";
    tester(testWord, "Word", "hello");

    char *testNum = "1";
    tester(testNum, "Number", "1");

    char *testOp = "+";
    tester(testOp, "Arithmetic Operator", "+");

    char *testSym = ";";
    tester(testSym, "Symbol", ";");

    return EXIT_SUCCESS;
}

// Function to test tokens
void tester(const char *testCase, const char *expectedType, const char *expectedText) {
    // Tokenize the test case and print results
    char *token = generateSpaceless(testCase);

    while (token != NULL) {
        TOKEN returnToken = parseToken(token);
        // Print test results
        printf((strcmp(tokenTypeToString(returnToken.type), expectedType) == 0 &&
                strcmp(returnToken.text, expectedText) == 0)
                   ? "Passed the test ☑\n"
                   : "Failed the test ☒\n");
        token = strtok(NULL, " ");
    }
}