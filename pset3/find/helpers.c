/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
#include "stdio.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    const int MAX = 65536;
    int* countArray = malloc(MAX * sizeof(int));
    int* sortedValues = malloc(n * sizeof(int));
    
    ///COUNTING SORT OF THE VALUES ARRAY
    
    //zeroes the counting array
    for(int i = 0; i < MAX; i++)
    {
        countArray[i] = 0;
    }
    
    //increments quantity of values in countArray
    for (int j = 0; j < n; j++)
    {
        countArray[values[j]] += 1;
    }
    
    for(int k = 0; k < MAX; k++)
    {
        countArray[k] += countArray[k - 1];
    }
    
    for (int x = 0; x < n; x++ )
    {
        sortedValues[countArray[values[x] - 1]] = values[x];
        countArray[values[x] - 1] += 1;
    }
    
    /// BINARY SEARCH OF THE VALUES ARRAY
    
    int min;
    int max;
    int middle;
    
    min = 0;
    max = n-1;
    middle = (n+1)/2;
    /*
    printf("\n");
    printf("INIT: min: %i max: %i middle: %i value: %i", sortedValues[min], sortedValues[max], sortedValues[middle], value);
    printf("\n");
    */
    
    do
    {
    if(value == sortedValues[middle] || value == sortedValues[min] || value == sortedValues[max])
    {
        free(sortedValues);
        return true;
        break;
    }
    else if(value > sortedValues[middle])
    {
        min = middle;
    }
    else if(value < sortedValues[middle])
    {
        max = middle;
    }
    middle = (min + max)/2;
    /*
    printf("INIT: min: %i max: %i middle: %i value: %i", sortedValues[min], sortedValues[max], sortedValues[middle], value);
    printf("\n");
    */
    }while (max-min > 1);
    
    free(sortedValues);
    return false;

    
    /* 
    //linear search
    for (int i = 0; i < n; i++) {
        if (value == sortedValues[i])
        {
            return true;
            free(sortedValues);
        }
    }
    */
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    const int MAX = 65536;
    int* countArray = malloc(MAX * sizeof(int));
    int* outArray = malloc(n * sizeof(int));
    
    //zeroes the counting array
    for(int i = 0; i < MAX; i++)
    {
        countArray[i] = 0;
    }
    
    //increments quantity of values in countArray
    for (int j = 0; j < n; j++)
    {
        countArray[values[j]] += 1;
    }
    
    for(int k = 0; k < MAX; k++)
    {
        countArray[k] += countArray[k - 1];
    }
    
    for (int x = 0; x < n; x++ )
    {
        outArray[countArray[values[x] - 1]] = values[x];
        countArray[values[x] - 1] += 1;
    }
    return;
}
