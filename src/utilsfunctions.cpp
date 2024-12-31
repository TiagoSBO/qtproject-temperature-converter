#include "utilsfunctions.h"

utilsfunctions::utilsfunctions(){
}

double celsiusToFahrenheit(double input) {
    return input * 1.8 + 32;
}

double celsiusToKelvin(double input) {
    return input + 273.15;
}

double fahrenheitToCelsius(double input) {
    return (input - 32) / 1.8;
}

double fahrenheitToKelvin(double input) {
    return (input + 459.67) * 5 / 9;
}
