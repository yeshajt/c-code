/*
 * isbn.c by Yesha Thakkar
 * October 15, 2018
 * tests to see whether an isbn is valid
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Initialize isbn variable
    long long isbn = get_long_long("ISBN: ");

    // Initializes the counter variable which adds up all of the values
    int counter = 0;

    // Starts the for loop
    for (int i = 0; i < 10; i++)
    {
        long long digit = (isbn % 10) * (10 - i);
        counter += digit;
        isbn = isbn / 10;
    }

    // Checks if the counter is divisible by 11
    if (counter % 11 == 0)
    {
        printf("%s\n", "YES");
    }
    else
    {
        printf("%s\n", "NO");
    }
}