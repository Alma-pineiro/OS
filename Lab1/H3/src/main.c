#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    Point p1;
    Point p2;

    p1.x = atof(argv[1]);
    p1.y = atof(argv[2]);
    p2.x = atof(argv[3]);
    p2.y = atof(argv[4]);

    float distance = CalculateDistance(p1, p2);

    printf("Distance: %.2f\n", distance);

    return 0;
}