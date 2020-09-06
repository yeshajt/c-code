/*
 * crack.c by Yesha Thakkar
 * November 21, 2018
 * Cracks passwords using C's DES-based hashing function
 */

#define _XOPEN_SOURCE
#include <crypt.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // First order of business: test the value of argc
    if (argc != 2)
    {
        printf("Usage: ./crack <hash>\n");
        return 1;
    }

    // Second: retrieve the hash from the command line and create a string with all of the letters of the alphabet
    string hash = argv[1];
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Total number of letters = 53
    int letter_value = 53;

    // Third: create an array for possible letter combinations that work
    string possible_passwords[];

    // Well we don't really have a salt so we're just gonna assign that the value of '\0'

    // Fourth: begin nested for loops
    for (int first = 1; first < letter_value; first++)
    {
        for (int second = 0; second < letter_value; second++)
        {
            for (int third = 0; third < letter_value; third++)
            {
                for (int fourth = 0; fourth < letter_value; fourth++)
                {
                    possible_passwords[0] = letters[first];
                    possible_passwords[1] = letters[second];
                    possible_passwords[2] = letters[third];
                    possible_passwords[3] = letters[fourth];
                }

                // Conditional tests to see if the hash of this function matches the command-line hash
                printf("Possible words = %s\n", possible_passwords);
            }
        }
    }

}