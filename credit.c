/*
 * credit.c by Yesha Thakkar
 * October 18, 2018
 * This program checks a credit card number
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    // Initializes the credit card number variable
    long long card_number;

    // Dowhile specification = number must be positive
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    // Count = tracks how many digits the number has
    int count = 0;
    long long number_of_digits = card_number;

    while (number_of_digits > 0)
    {
        number_of_digits = number_of_digits / 10;
        count++;
    }
    // Type specifications are at the end of the program

    // Initializes a counter for the for loop
    int counter = 0;

    // Initializes a different variable for card_number
    long long card_number_evens = card_number;

    // The mathemical formula for even numbers
    for (int i = 0; i <= 16; i += 2)
    {
        int digit = 2 * ((card_number_evens / 10) % 10);

        // This for loop splits the multiplied digit if it's a two-digit number
        int sum = 0;
        for (int k = 1; k <= 2; k++)
        {
            sum = (digit % 10);
            digit = digit / 10;
            counter += sum;
        }

        card_number_evens = card_number_evens / 100;
    }

    // Initializes a different variable for card_number
    long long card_number_odds = card_number;

    // The mathematical formula for odd numbers
    for (int j = 1; j <= 16; j += 2)
    {
        int digit = card_number_odds % 10;
        counter += digit;
        card_number_odds = card_number_odds / 100;
    }

    // Nested if statements test whether the card is valid, card type specifications included
    if (counter % 10 == 0)
    {
        if (count == 13 && (long long)(card_number / pow(10, 12)) == 4)
        {
            printf("VISA\n");
        }
        else if (count == 16 && (long long)(card_number / pow(10, 15)) == 4)
        {
            printf("VISA\n");
        }
        else if (count == 15 && ((long long)(card_number / pow(10, 13)) == 34 || (long long)(card_number / pow(10, 13)) == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (long long)(card_number / pow(10, 14)) >= 51 && (long long)(card_number / pow(10, 14)) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}