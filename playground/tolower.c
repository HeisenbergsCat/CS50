#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int charToIndex(char letter)
{
    if(letter == '\'')
    {
        return 0;
    }
    return (int)letter - 'a';
}

int main()
{
    printf("%i", charToIndex('a'));
}