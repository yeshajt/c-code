/*
 * cash.c by Yesha Thakkar
 * October 2, 2018
 * Calculates the least number of coins necessary to give a user change
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    //global change_owed user input variable
    float change_owed;
    //dowhile ensures that user input is valid (try-and-except in python)
    do
    {
        //user input
        change_owed = get_float("Enter the change owed: ");
    }
    //while ensures that the loop keeps running if the input is not positive or not a decimal
    while (change_owed < 0);

    //converts dollars to cents for convenience
    int cents_owed = round(change_owed * 100);

    //the counter variable keeps track of the number of coins, initially set to zero
    int counter = 0;

    //calculates the number of quarters and adds to the counter
    int quarters = cents_owed / 25;
    int new_change = cents_owed - (quarters) * 25;
    counter += quarters;

    //calculates the number of dimes from the remaining amount and adds to the counter
    int dimes = new_change / 10;
    new_change = new_change - (dimes) * 10;
    counter += dimes;

    //calculates the number of nickels from the remaining amount and adds to the counter
    int nickels = new_change / 5;
    new_change = new_change - (nickels) * 5;
    counter += nickels;

    //the remaining change is just pennies and adds to the counter
    counter += new_change;

    //prints counter
    printf("%i\n", counter);
}