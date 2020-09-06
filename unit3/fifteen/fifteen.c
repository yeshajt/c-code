// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    int total_tiles = d * d;

    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            total_tiles = total_tiles - 1;
            board[row][column] = total_tiles;
        }
    }

    //decide whether or not to swap 1 and 2
    if (d % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }
    // TODO
}

// Prints the board in its current state
void draw(void)
{
    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            if (board[row][column] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2i ", board[row][column]);
            }
        }
        printf("\n");
    }
    // TODO
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // TODO
    //CLEAN THIS UP LATER!!!
    int row_tile;
    int column_tile;
    // Find the location of the number that the user is looking for and the blank tile
    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            if (board[row][column] == 0)
            {
                // Create new variables for swapping purposes
                blank_row = row;
                blank_col = column;
            }
            if (board[row][column] == tile)
            {
                // Same thing: swapping purposes
                row_tile = row;
                column_tile = column;
            }
        }
    }
    // Ensures that diagonals are not included
    if (blank_row != row_tile && blank_col != column_tile)
    {
        return false;
    }

    // Checks column distance from the blank tile
    if (abs(column_tile - blank_col) + abs(row_tile - blank_row) != 1)
    {
        return false;
    }

    // Swaps the tiles
    else
    {
        int temp_row = blank_row;
        int temp_col = blank_col;
        blank_row = row_tile;
        blank_col = column_tile;
        row_tile = temp_row;
        column_tile = temp_col;
        board[blank_row][blank_col] = 0;
        board[row_tile][column_tile] = tile;
        return true;
    }
    // If there is blank (0) next to the tile, swap positions
    // If not, return false

    //NOTE TO FUTURE SELF: There is a global variable called blank_row
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    // TODO

    // Set a counter
    int counter = 1;

    // Go through the board and check if each tile is in order
    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            if (counter % (d * d) == 0)
            {
                counter = 0;
            }
            if (board[row][column] != counter)
            {
                return false;
            }
            counter += 1;
        }
    }
    return true;
}
