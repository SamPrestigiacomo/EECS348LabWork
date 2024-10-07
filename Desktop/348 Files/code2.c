#include <stdio.h>

double convert_temperature(double temp, char input_unit, char target_unit) {
    if (input_unit == 'C') {
        if (target_unit == 'F'){
            return (temp * 9 / 5) + 32; //Celsius to Fahrenheit
        }
        else if (target_unit == 'K') {
            return temp + 273.15; //Celsius to Kelvin
        }
    }
    else if (input_unit == 'F') {
        if (target_unit == 'C') {
            return (temp - 32) * 5/9; //Fahrenheit to Celsius
        }
        else if (target_unit == 'K') {
            return (temp - 32) * 5/9 + 273.15; //Fahrenheit to Kelvin
        }
    }
    else if (input_unit == 'K') {
        if (target_unit == 'C') {
            return temp - 273.15; //Kelvin to Celsius
        }
        else if (target_unit == 'F') {
            return (temp - 273.15) * 9.0/5.0 + 32; //Kelvin to Fahrenheit
        }
    }
    return temp; //input_unit and target_unit are the same
}

void categorize_temperature(double temp_in_celsius) {
    if (temp_in_celsius < 0) {
        printf("Temperature Category: Freezing\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (temp_in_celsius >= 0 && temp_in_celsius < 10) {
        printf("Temperature Category: Freezing\n");
        printf("Weather advisory: It's cold outside.\n");
    }
    else if (temp_in_celsius >= 10 && temp_in_celsius < 25) {
        printf("Temperature Category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    }
    else if (temp_in_celsius >= 25 && temp_in_celsius < 35) {
        printf("Temperature Category: Hot\n");
        printf("Weather advisory: It's hot.\n");
    }
    else if (temp_in_celsius >= 35) {
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}

int main() {
    double temperature;
    char input_unit, target_unit;
    int c;

    printf("Enter the temperature value: ");
    fflush(stdout);
    if (scanf("%lf", &temperature) != 1) {
        printf("Error reading temperature.\n");
        return 1;
    }

    // Clear input buffer
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the input unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    fflush(stdout);
    input_unit = getchar();

    // Clear input buffer
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the target unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    fflush(stdout);
    target_unit = getchar();

    // Clear input buffer
    while ((c = getchar()) != '\n' && c != EOF);


    double converted_temp = convert_temperature(temperature, input_unit, target_unit);
    printf("Converted Temperature: %.2f %c\n", converted_temp, target_unit);

    double temp_in_celsius;
    if (target_unit == 'C' || target_unit == 'c') {
        temp_in_celsius = converted_temp;
    }
    else if (target_unit == 'F' || target_unit == 'f') {
        temp_in_celsius = (converted_temp - 32) * 5.0/9.0;
    }
    else if (target_unit == 'K' || target_unit == 'k') {
        temp_in_celsius = converted_temp - 273.15;
    }

    categorize_temperature(temp_in_celsius);
    return 0;
}