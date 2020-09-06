// Greets a user by their name

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Tells the user what to do if the input is not just one name
    if (argc != 2)
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }
    // Greets the user given their name
    printf("Hello, %s!\n", argv[1]);

    // Success
    return 0;
}
