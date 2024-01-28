#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Get input from the user
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Perform the calculation based on the operator
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;

        default:
            printf("Error: Invalid operator.\n");
            return 1; // Exit with an error code
    }

    // Display the result
    printf("Result: %.2lf\n", result);

    return 0; // Exit successfully
}
