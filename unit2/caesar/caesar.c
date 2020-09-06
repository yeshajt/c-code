/*
 * caesar.c by Yesha Thakkar
 * November 7, 2018
 * Encrypts messages using the Caesar Cipher
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ciphertext_converter(char letter, int ascii_number, int key);

int main(int argc, string argv[])
{
    // Test the number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // User input statement
    string plaintext = get_string("plaintext: ");

    // Converts the key to an integer
    int key = atoi(argv[1]);

    // Prints "ciphertext"
    printf("ciphertext: ");

    // Tests whether a character is a letter and decides what operation to perform
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Uppercase letter test
            if (isupper(plaintext[i]))
            {
                ciphertext_converter(plaintext[i], 'A', key);
            }
            // Lowercase letter test
            else
            {
                ciphertext_converter(plaintext[i], 'a', key);
            }
        }
        // Handles spaces and punctuation
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    // Prints a new line
    printf("\n");

    // Success!!
    return 0;
}

// Function turns individual characters into ciphertext using modulo
void ciphertext_converter(char letter, int ascii_number, int key)
{
    int character_number = letter - ascii_number;
    int ciphertext_number = (character_number + key) % 26;
    char ciphertext_letter = (char)(ciphertext_number + ascii_number);
    printf("%c", ciphertext_letter);
}
