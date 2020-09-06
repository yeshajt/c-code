/*
 * intials.c by Yesha Thakkar
 * October 31, 2018
 * Prints out a person's intials given their name
 * Less comfortable version
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user input
    string name = get_string();
    // For loop finds the initials
    printf("%c", toupper(name[0]));
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ' && name[i + 1] != '\0')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}
