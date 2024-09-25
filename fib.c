#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long recursive(int input);
unsigned long long iterative(int input);

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is passed
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <input_num> <method>\n", argv[0]);
        return 1;
    }

    // Convert the first argument to integer
    int input_num = atoi(argv[1]);

    // Use the input number directly for Fibonacci calculation
    unsigned long long result;
    if (strcmp(argv[2], "r") == 0) 
    {
        result = recursive(input_num);
    } 
    else if (strcmp(argv[2], "i") == 0) 
    {
        result = iterative(input_num);
    } 

    // Output the Fibonacci number
    printf("%llu\n", result);

    return 0;
}

unsigned long long recursive(int input) {
    if (input == 1) 
    {
        return 0;
    }
    if (input == 2)
    {
        return 1;
    }
    return recursive(input - 1) + recursive(input - 2);
}

unsigned long long iterative(int input) {
    if (input == 1) 
    {
        return 0;
    }
    if (input == 2) 
    {
        return 1;
    }
    unsigned long long a = 0;
    unsigned long long b = 1;
    for (int i = 3; i <= input; i++) 
    {
        unsigned long long temp = b;
        b = b + a;
        a = temp;
    }
    return b;
}
