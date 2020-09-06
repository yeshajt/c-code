/*
 * fahrenheit.c by Yesha Thakkar
 * September 27, 2018
 * converts a temperature in celsius to fahrenheit
 */

#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // user input in celsius
    float celsius = get_float("Enter the temperature in celsius: ");
    // celsius to fahrenheit conversion
    float fahrenheit = ((celsius * (9.0 / 5.0)) + 32);
    // prints the result
    printf("%.1f\n", fahrenheit);
}