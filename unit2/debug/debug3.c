// ########## USE AND KEEP AT LEAST ONE PRINT STATEMENT ##########
// ########## PRINT THE 'answer' VARIABLE IN EACH CASE TO SEE WHAT'S HAPPENING ##########
// ########## TEST WITH ALL THE POSSIBLE OPERATORS ##########

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{


    if (argc != 4)
    {
        printf("Usage: ./debug3 <number> <operator> <number>\n");
        return 1;
    }

    if (strlen(argv[2]) != 1)
    {
        printf("Enter a valid operator (+, -, x, /, %%)\n");
        return 1;
    }

    float number1 = atof(argv[1]);
    float number2 = atof(argv[3]);
    float answer;

    // The problem is that the program is performing all of the cases because there are no return statements
    printf("DEBUG: operator = %c\n", argv[2][0]);
    switch (argv[2][0])
    {
        case '+':
            answer = number1 + number2;
            printf("DEBUG: answer = %f\n", answer);
            return answer;

        case '-':
            answer = number1 - number2;
            printf("DEBUG: answer = %f\n", answer);
            return answer;

        case 'x':
            answer = number1 * number2;
            printf("DEBUG: answer = %f\n", answer);
            return answer;

        case '/':
            answer = number1 / number2;
            printf("DEBUG: answer = %f\n", answer);
            return answer;

        case '%':
            answer = number1 - (number2 * (number1 / number2));
            printf("DEBUG: answer = %f\n", answer);
            return answer;

        default:
            printf("Usage: ./debug3 <number> <operator> <number>\n");
            return 1;
    }

    printf("Result: %f", answer);
}