// Calculates how many pennies a user would get if their change doubles each day using command line information

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(int argc, string argv[])
{
    // Ensures that there are only two arguments
    if (argc != 3)
    {
        printf("Usage: ./pennies <days of the month> <pennies on first day>\n");
        return 1;
    }
    // Ensures that the number of days is between 28 and 31
    int days = atoi(argv[1]);
    if (days < MIN_DAYS || days > MAX_DAYS)
    {
        printf("Days in month must be between 28 and 31\n");
        return 1;
    }
    // Ensures that the number of pennies is not negative
    int pennies = atoi(argv[2]);
    if (pennies <= 0)
    {
        printf("Pennies must be a positive number\n");
        return 1;
    }
    long long total = 0;
    // Add double the amount of pennies of the previous day each day
    for (int i = 0; i < days; i++)
    {
        total += pennies * pow(2, i);
    }

    // Output the total as dollars and cents only
    printf("$%.2f\n", ((double) total) / 100);

    // Success!
    return 0;
}
