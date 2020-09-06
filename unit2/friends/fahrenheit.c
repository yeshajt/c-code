// Converts degrees C to degrees F by collecting info at command line

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Ensures that there is only one argument
    if (argc != 2)
    {
        printf("Usage: ./fahrenheit <number>\n");
        return 1;
    }

    // Else converts to fahrenheit
    float celsius = atof(argv[1]);
    float fahrenheit = (celsius * 9) / 5 + 32;
    printf("F: %.1f\n", fahrenheit);

    // Success!
    return 0;
}
