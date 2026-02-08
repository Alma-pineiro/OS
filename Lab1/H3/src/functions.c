#include "../include/functions.h"
#include <math.h>

float CalculateDistance(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float total = sqrt(dx * dx + dy * dy);
    return total;
}