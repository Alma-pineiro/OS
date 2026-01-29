#include "../include/functions.h"

#include <ctype.h>

/**
 * @brief Converts Celsius to Fahrenheit.
 * @param[in] celsius The temperature in Celsius.
 * @return The temperature in Fahrenheit.
 */
float CelsiusToFahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}

/**
 * @brief Converts Celsius to Kelvin.
 * @param[in] celsius The temperature in Celsius.
 * @return The temperature in Kelvin.
 */
float CelsiusToKelvin(float celsius) { return celsius + 273.15; }

/**
 * @brief Converts Fahrenheit to Celsius.
 * @param[in] fahrenheit The temperature in Fahrenheit.
 * @return The temperature in Celsius.
 */
float FahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

/**
 * @brief Converts Kelvin to Celsius.
 * @param[in] kelvin The temperature in Kelvin.
 * @return The temperature in Celsius.
 */
float KelvinToCelsius(float kelvin) { return kelvin - 273.15; }