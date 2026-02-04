#include "../include/functions.h"
#include <stddef.h>
#include <math.h>

int Calculate(float num1, float num2, char op, float *result){

  if (result == NULL)
    {
        return -1;
    }

    switch (op)
    {
        case '+':
            *result = num1 + num2;
            break;

        case '-':
            *result = num1 - num2;
            break;

        case 'x':
        case '*':
            *result = num1 * num2;
            break;

        case '/':
            if (num2 == 0)
            {
                return -1;
            }
            *result = num1 / num2;
            break;

        case '^':
            *result = pow(num1, num2);
            break;

        default:
            return -1;
    }

    return 0;

}