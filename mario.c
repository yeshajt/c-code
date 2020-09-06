/*
 * mario.c by Yesha Thakkar
 * October 9, 2018
 * prints out a double half-pyramid of a user-specified height
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initializes user input
    int height;

    //the dowhile loop gets user input
    do
    {
        //user input can be from 0 to 23
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    //initialize spaces;
    string space = " ";
    string hash = "#";

    //the for loop is what generates the pyramids
    //the for loop establishes three main components: the first half-pyramid, the spaces, and the second half-pyramid
    for (int i = 1; i <= height; i++)
    {
        //initializes the number of spaces and the number of hashes
        int spaces_count;
        int hashes_count;

        //component 1: the first half-pyramid

        //for loop 1: calculates the number of spaces
        for (spaces_count = height - i; spaces_count > 0; spaces_count--)
        {
            printf("%s", space);
        }
        //for loop 2: calculates the number of hashes
        for (hashes_count = 0; hashes_count < i; hashes_count++)
        {
            printf("%s", hash);
        }

        //component 2: have two spaces between each line
        //since we have a predetermined number of spaces set, it's more efficient to simply type them out instead of a for loop
        printf("%s", space);
        printf("%s", space);

        //component 3: the second half-pyramid (same for loops, reverse order)

        //for loop 1: calculates the number of hashes
        for (hashes_count = 0; hashes_count < i; hashes_count++)
        {
            printf("%s", hash);
        }
        //for loop 2 is superfluous because the pyramid is left-aligned

        //prints new line
        printf("\n");

    }


}