#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/functions.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Error: Invalid number of arguments.\n");
  }

  if (argv[2][0] != 'C' && argv[2][0] != 'F' && argv[2][0] != 'K') {
    printf("Error: Invalid unit.\n");
  }

  if (argv[2][0] == 'C') {
    float celsius = atof(argv[1]);
    float fahrenheit = CelsiusToFahrenheit(celsius);
    float kelvin = CelsiusToKelvin(celsius);
    printf("%s %c is %.2f F and %.2f K\n", argv[1], argv[2][0], fahrenheit,
           kelvin);

  } else if (argv[2][0] == 'F') {
    float fahrenheit = atof(argv[1]);
    float celsius = FahrenheitToCelsius(fahrenheit);
    float kelvin = CelsiusToKelvin(celsius);
    printf("%s %c is %.2f C and %.2f K\n", argv[1], argv[2][0], celsius,
           kelvin);

  } else if (argv[2][0] == 'K') {
    float kelvin = atof(argv[1]);
    float celsius = KelvinToCelsius(kelvin);
    float fahrenheit = CelsiusToFahrenheit(celsius);
    printf("%s %c is %.2f C and %.2f F\n", argv[1], argv[2][0], celsius,
           fahrenheit);
  }
}
