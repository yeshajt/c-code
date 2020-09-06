// Helper functions

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

#define MAX_VALUE 65536

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm – binary search

    // Finds the middle of the sorted array
    int length = n;

    int middle_value = (n - 1) / 2;
    while (length > 0)
    {
        // Tests whether this value is less or more than the requested value
        if (values[middle_value] == value)
        {
            return true;
        }
        if (values[middle_value] < value)
        {
            middle_value = (middle_value + n) / 2;
            length = length / 2;
        }
        else
        {
            middle_value = middle_value / 2;
            length = length / 2;
        }
    }

    // If it doesn't find the number, returns false
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm – counting sort

    int counter[MAX_VALUE] = {0};
    // Goes through the first array and looks at each value
    for (int i = 0; i < n; i++)
    {
        int current_value = values[i];
        // Increments the value of that index in the second array
        counter[current_value] += 1;
    }
    // Goes through the second array and sorts in terms of how many of each index there are
    int placeholder_index = 0;
    for (int j = 0; j < MAX_VALUE; j++)
    {
        if (counter[j] != 0)
        {
            values[placeholder_index] = j;
            placeholder_index += 1;
        }
    }
    return;
}
