#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// Creates a structure that globalizes the solved board and the playing board
struct
{
    // This is a 3x3 magic square

    // This is the solved board that the program will compare user input with
    int solved_board[3][3];

    // This is the board that the user will see and interact with
    int playing_board[3][3];
}
board;

// Function prototypes
void create_squares(void);
void user_squares(void);
void check_value(int column, int row, int val);
void update_numbers(void);
bool check_win(void);

int main(void)
{
    // Create the solved board
    create_squares();

    // Initialize variables and collect user input
    int column;
    int row;
    int value;
    do
    {
        column = get_int("Enter a column value: ");
        row = get_int("Enter a row value: ");
        value = get_int("Enter your guess: ");
        printf("\n");
        check_value(column, row, value);
    }
    while (column < 1 || column > 3 || row < 1 || row > 3 || value < 1 || value > 9 || !check_win());

    // Success!
    printf("Great job, you did it!\n");
    return 0;
}

// This function creates the solved board
void create_squares(void)
{
    int square = 9;
    int i = 0, j = 1, k;

    for (k = 1; k <= square; ++k)
    {
        // Assigns the values of i, j, and k, changes the values of i and j based on the next number
        board.solved_board[i][j] = k;
        i = i - 1;
        j = j + 1;

        // Checks to see whether putting a number in the next location is possible given the dimension (3)
        if (k % 3 == 0)
        {
            i += 2;
            j--;
        }
        else
        {
            if (j == 3)
            {
                j -= 3;
            }
            else if (i < 0)
            {
                i += 3;
            }
        }
    }

    // Moves to the playing board
    user_squares();
}

// This function creates the playing board
void user_squares(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float random_value = drand48();

            if (random_value > 0.1)
            {
                board.playing_board[i][j] = board.solved_board[i][j];
                printf("%d ", board.playing_board[i][j]);
            }

            else
            {
                board.playing_board[i][j] = 0;
                if (board.playing_board[i][j] == 0)
                {
                    printf("_ ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

// This function checks the user input
void check_value(int column, int row, int val)
{
    // Adjust the row and column values for indexing
    column = column - 1;
    row = row - 1;

    if (board.playing_board[row][column] != 0)
    {
        printf("This value already exists\n");
    }
    else
    {
        if (board.solved_board[row][column] == val)
        {
            printf("That's right, good job!\n");
            board.playing_board[row][column] = val;
        }
        else
        {
            printf("Sorry, that's incorrect!\n");
        }
    }
    update_numbers();
}

// This function updates the board
void update_numbers(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.playing_board[i][j] != 0)
            {
                printf("%d ", board.playing_board[i][j]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
    check_win();

}

// This function checks to see if the user has won
bool check_win(void)
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.playing_board[i][j] != 0)
            {
                counter += 1;
            }
        }
    }

    if (counter == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}