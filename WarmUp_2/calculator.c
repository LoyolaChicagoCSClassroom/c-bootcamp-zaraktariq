#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    float num1;
    float num2;

    printf("Please input the first number: ");
    // scan formatted("Expect a float", saved to the memory position of num1);
    scanf(("%f"), &num1);
    printf("Please input the second number: ");
    scanf(("%f"), &num2);
    
    // math operations
    printf("%f + %f = %f\n", num1, num2, num1+num2);
    printf("%f - %f = %f\n", num1, num2, num1-num2);
    printf("%f / %f = %f\n", num1, num2, num1/num2);
    printf("%f * %f = %f\n", num1, num2, num1*num2);
}