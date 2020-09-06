// ########## USE AND KEEP AT LEAST THREE PRINT STATEMENTS ##########


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./debug2 <integer>\n");
        return 1;
    }

    int reversedInt = 0, remainder = 0;

    int originalInt = atoi(argv[1]);

    // The problem is that the user is modifying originalInt in the while loop and then using the modified originalInt in the if statements
    // The solution to the problem would be to create a placeholder variable for originalInt

    int placeholder = originalInt;

    while (placeholder != 0)
    {
        remainder = placeholder % 10;
        reversedInt = reversedInt * 10 + remainder;
        placeholder /= 10;
        printf("DEBUG: originalInt = %i\n", placeholder);
    }

    if (originalInt == reversedInt)
    {
        printf("%d is a palindrome. \n", originalInt);
    }
    else
    {
        printf("%d is not a palindrome. \n", originalInt);
    }

}