/*
 * calc.c by Yesha Thakkar
 * November 6, 2018
 * Performs addition, subtraction, multiplication, division, and modulo
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool input_test(int c, string s[]);

int main(int argc, string argv[])
{
    // Determines if argc == 4
    if (argc != 4)
    {
        printf("Usage: ./calc <number> <operation> <number>\n");
        return 1;
    }

    // Tests the length of the operation string
    if (strlen(argv[2]) != 1)
    {
        printf("Enter a valid operation\n");
        return 1;
    }

    // Converts the number strings into numbers
    float number_1 = atof(argv[1]);
    float number_2 = atof(argv[3]);

    // Use input_test to test whether user input is just numbers
    bool number1 = input_test(1, argv);
    bool number2 = input_test(3, argv);

    if (number1 && number2)
    {
        // Stores the operation as a character to test later
        char operand = argv[2][0];

        // Switch used in place of if statements for cohesion
        switch (operand)
        {
            case '+':
                printf("%f\n", number_1 + number_2);
                return 0;
            case '-':
                printf("%f\n", number_1 - number_2);
                return 0;
            case 'x':
                printf("%f\n", number_1 * number_2);
                return 0;
            case '/':
                printf("%f\n", number_1 / number_2);
                return 0;
            case '%':
                printf("%f\n", number_1 - (number_2 * (int)(number_1 / number_2)));
                return 0;
            default:
                printf("Enter a vaild operation (addition, subtraction, division, multiplication, or mod)\n");
                return 1;
        }
    }
    else
    {
        printf("Enter a number\n");
        return 1;
    }
}

bool input_test(int c, string s[])
{
    for (int i = 0, n = strlen(s[c]); i < n; i++)
    {
        if (!isdigit(s[c][i]) && (s[c][i] != '.' && (s[c][i] != '-')))
        {
            //counter += 1;
            return false;
        }
    }
    return true;
}