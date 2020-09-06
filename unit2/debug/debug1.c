// ########## USE AND KEEP AT LEAST ONE PRINT STATEMENT ##########


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    int value = 0;

    while (!(value == 10) || !(value == 20))
    {
        // The issue is that this is an infinite loop
        printf("DEBUG: Value = %i\n", value);
        value = 10;
        // Fix this by returning value
        return value;
    }

}