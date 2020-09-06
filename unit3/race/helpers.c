// Helper functions for the sort race

#include <cs50.h>
#include "helpers.h"
#include <string.h>

// Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    if (strlen(str) != 2)
    {
        return false;
    }
    if (str[0] != '-')
    {
        return false;
    }
    else
    {
        if (str[1] != 'a' && str[1] != 'b' && str[1] != 'r' && str[1] != 's')
        {
            return false;
        }
    }
    return true;
}

// Sorts array of n values using bubble sort
void bubble(int values[], int n)
{
    for (int j = 0; j < (n - 1); j++)
    {
        // For loop runs through the array and compares values next to each other
        for (int i = 0; i < (n - 1); i++)
        {
            if (values[i] > values[i + 1])
            {
                int placeholder = values[i + 1];
                values[i + 1] = values[i];
                values[i] = placeholder;
            }
        }
    }
    return;
}


// Sorts array of n values using selection sort
void selection(int values[], int n)
{
    // For loop finds the current minimum of the array
    for (int i = 0; i < n; i++)
    {
        int current_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[current_index] > values[j])
            {
                current_index = j;
            }
        }

        // Swaps the current minimum with the end of the sorted portion of the array
        int placeholder = values[current_index];
        values[current_index] = values[i];
        values[i] = placeholder;
    }
    return;
}

// Sorts array of n values using insertion sort
void insertion(int values[], int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        // For loop tests all of the values before i to see if anything is bigger
        for (int j = i; j > 0; j--)
        {
            if (values[j] < values[j - 1])
            {
                int placeholder = values[j - 1];
                values[j - 1] = values[j];
                values[j] = placeholder;
            }
        }
    }
    return;
}
