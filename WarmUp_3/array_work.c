#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    // array initialization, in the form of "type varName"
    int numArray[5] = {1, 2, 3, 4, 5};
    // total sum of the array
    int sum = 0;
    // average over the array
    double average;
    // i for while loop
    int i = 0;
    // alias size of array
    // calculates the size of an array in bytes and then divide by the size of one element to get the number of elements
    int size = sizeof(numArray) / sizeof(numArray[0]);

    // sum loop
    while(i < size) {
        sum += numArray[i];
        i++;
    }

    // calculate avg
    average = (double)sum / size;

    // output findings
    printf("The average is: %.1f\n", average);
    printf("The sum is: %.d\n", sum);
}