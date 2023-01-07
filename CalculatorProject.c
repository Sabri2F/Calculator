#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EXIT_COMMAND "exit"

// Function prototypes
long add(long a, long b);
long multiply(long a, long b);
double divide(double a, double b);
long subtract(long a, long b);
long power(long a, long b);
void help();

int main() {
    // Print the help menu
    // Display help menu
    help();

    // Open log file
    FILE *log_file = fopen("calculator.log", "w");

    // Get user input
    char input[100];
    while (1) {
        printf("$ ");
        scanf("%[^\n]s", input);
        getchar();

        // Write user input to log file
        fprintf(log_file, "%s\n", input);

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Parse input
        char operator[5];
        long a, b;
        int num_items = sscanf(input, "%ld %[^0-9] %ld", &a, operator, &b);

        // Check if input is valid
        if (num_items != 3) {
            printf("Error: Invalid input\n");
            continue;
        }
        // Perform the calculation and print the result
        double result = 0;
        int error = 0;
        if(strcmp(operator, "+") == 0){
            result = add(a, b);
        }
        else if(strcmp(operator, "*") == 0){
            result = multiply(a, b);
        }
        else if(strcmp(operator, "/") == 0){
            if (b == 0) {
                    printf("Error: Cannot divide by zero!\n");
                    error = 1;
        } else {
                    result = divide(a, b);
                }
        }
        else if(strcmp(operator, "-") == 0){
            result = subtract(a, b);
        }
        else if(strcmp(operator, "^") == 0){
            result = power(a, b);
        }
        else{
            printf("Error: Invalid operator!\n");
            error = 1;
        }
        
        if (!error) {
            printf("Result: %f\n", result);
        }
        
    }
    // Close the log file
    fclose(log_file);
    return 0;
}

// Function definitions
// Function to add two numbers
long add(long a, long b) {
    return a + b;
}

// Function to multiply two numbers
long multiply(long a, long b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}

// Function to subtract two numbers
long subtract(long a, long b) {
    return a - b;
}

// Function to calculate power of a number
long power(long a, long b) {
    long result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

// Function to display help menu
void help() {
    printf("Calculator\n");
    printf("----------\n");
    printf("Supported operators:\n");
    printf("1) Add:      $ 35.5 + 45\n");
    printf("2) Multiply: $ 7 * 15\n");
    printf("3) Divide:   $ 64 / 4\n");
    printf("4) Subtract: $ -18 - 4\n");
    printf("5) Power:    $ 2 ^ 3\n");
    printf("6) Exit:     $ exit\n");
    printf("Enter any expression and press ENTER to see the result\n");
}
