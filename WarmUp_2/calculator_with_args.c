#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv) {
    if(argc < 3) {
        printf("this program requires 2 inputs\n");
        return EXIT_FAILURE;
    } else {
        int val1 = strtol(argv[1], NULL, 10);
        int val2 = strtol(argv[2], NULL, 10);

        printf("%d + %d = %d\n", val1, val2, val1 + val2);
        printf("%d - %d = %d\n", val1, val2, val1 - val2);
        printf("%d / %d = %d\n", val1, val2, val1 / val2);
        printf("%d * %d = %d\n", val1, val2, val1 * val2);
    }
}