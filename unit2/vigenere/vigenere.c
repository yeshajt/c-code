/*
 * vigenere.c by Yesha Thakkar
 * November 17, 2018
 * Encrypts a message using the Vigenere Cipher
 * Fifth time's the charm!
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Tests the value of argc
    if (argc != 2)
    {
        printf("Usage: ./vigenere key");
        return 1;
    }

    // Tests the components of the key
    for (int j = 0, m = strlen(argv[1]); j < m; j++)
    {
        if (!isalpha(argv[1][j]))
        {
            printf("The key can only be letters\n");
            return 1;
        }
    }
    // Get plaintext, key, and print "ciphertext"
    string plaintext = get_string("plaintext: ");
    string key = argv[1];
    printf("ciphertext: ");

    // Key index is independent of i to account for non-alphabetical plaintext elements
    int key_index = 0;

    // Starts the for loop
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int ciphertext_value = 0;

        // Handles non-alphabetical elements
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }

        // Handles alphabetical elements using a method similar to the caesar cipher
        else
        {
            // Plaintext_value and key_value are the numerical values of the elements
            int plaintext_value = (isupper(plaintext[i]) ? (plaintext[i] - 65) : (plaintext[i] - 97));
            int key_element = key_index % strlen(key);
            int key_value = (isupper(key[key_element]) ? (key[key_element] - 65) : (key[key_element] - 97));

            // Main function: mods plaintext_value + key_value
            ciphertext_value = (plaintext_value + key_value) % 26;

            // Tests the casing of plaintext element to match the ciphertext element
            printf("%c", isupper(plaintext[i]) ? (ciphertext_value += 65) : (ciphertext_value += 97));

            // Increments the key index value only if the plaintext element is not a space or symbol
            key_index += 1;
        }
    }

    // Prints a new line
    printf("\n");

    // Success!
    return 0;
}