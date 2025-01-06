#include "utilsfunctions.h"

utilsfunctions::utilsfunctions(){
}

double celsiusToFahrenheit(double celToFah) {
    return celToFah * 1.8 + 32;
}

double celsiusToKelvin(double celtoKel) {
    return celtoKel + 273.15;
}

double fahrenheitToCelsius(double fahToCel) {
    return (fahToCel - 32) / 1.8;
}

double fahrenheitToKelvin(double fahToKel) {
    return (fahToKel + 459.67) * 5 / 9;
}

