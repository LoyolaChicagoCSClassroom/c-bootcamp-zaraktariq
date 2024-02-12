#include <stdio.h>

int main() {
    // char array to store string we will reverse
    char str[64];

    // accept string input, with max size
    printf("Input a string to be reversed:\n");
    scanf("%63s", str);

    // Get the length of the input string
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Reversal loop
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Print the reversed string
    printf("The reverse is %s\n", str);
    
}