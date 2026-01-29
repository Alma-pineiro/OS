#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Error: Invalid number of arguments.\n");
  }

  if (argv[2] != 'C' && argv[2] != 'F' && argv[2] != 'K') {
    printf("Error: Invalid unit.\n");
  }

  if (argc == 'C') {
    float celsius = atof(argv[1]);
    float fahrenheit = CelsiusToFahrenheit(celsius);
    float kelvin = CelsiusToKelvin(celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);
  } else if (argc == 'F') {
    float fahrenheit = atof(argv[1]);
    float celsius = FahrenheitToCelsius(fahrenheit);
    float kelvin = CelsiusToKelvin(celsius);
    printf("Celsius: %.2f\n", celsius);
    printf("Kelvin: %.2f\n", kelvin);
  } else if (argc == 'K') {
    float kelvin = atof(argv[1]);
    float celsius = KelvinToCelsius(kelvin);
    float fahrenheit = CelsiusToFahrenheit(celsius);
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
  }
}
