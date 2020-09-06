/*
 * pennies.c by Yesha Thakkar
 * October 4, 2018
 * calculates the sum of getting a doubled amount of money each day for a month
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //since overload is a potential problem in this program, long long will be used for most numerical data
    //initializes days of the month to be used in and out of the dowhile loop
    int days_in_month;
    //initializes number of pennies to be used in and out of the dowhile loop
    int pennies;
    //dowhile checks to ensure that the input is within range
    do
    {
        //days of the month should be either 28, 29, 30, or 31
        days_in_month = get_int("Days in month: ");
    }
    //while ensures that days of the month is restricted to 4 values
    while (days_in_month < 28 || days_in_month > 31);

    do
    {
        //there must be a positive number of pennies
        pennies = get_int("Pennies on first day: ");
    }
    //while ensures that pennies is restricted to positive values only
    while (pennies < 1);

    //the mathematical function that calculates the PENNIES
    long long total_pennies = (pennies * exp2(days_in_month)) - pennies;
    //the above solution is only a temporary fix to the extra cents issue even though it generally works

    //divides the income by 100 to get a dollar value
    //since this is a floating point, using a double is probably a good idea
    double total_dollars = total_pennies / 100.00;

    //prints the total value in dollars
    printf("$%.2f\n", total_dollars);

}