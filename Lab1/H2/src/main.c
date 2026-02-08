#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [Number1] [Operator] [Number2]\n", argv[0]);
        return -1;
    }

    float num1 = atof(argv[1]);
    char op = argv[2][0];
    float num2 = atof(argv[3]);
    float result = 0.0f;

    int final = Calculate(num1, num2, op, &result);

    if (final == 0) {
        printf("%.2f %c %.2f = %.2f\n", num1, op, num2, result);
    } else {
        if (op == '/' && num2 == 0) {
            printf("Error: Division by zero\n");
        } else {
            printf("Error: Invalid operator\n");
        }
    }

    return 0;
}
