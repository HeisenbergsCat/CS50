#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trie.h"

void printWord(char *filename)
{
    FILE *testFile;
    testFile = fopen(filename, "r");

    if (!testFile)
    {
        printf("LOADING ERROR!");
    }

    char buffer[45 * sizeof(char)];
    int index = 0;

    while (fscanf(testFile, "%s", buffer) == 1)
    {
        printf("%i: %s \n", index, buffer);
        index ++;
    }

    fclose(testFile);
}

int main() {

    printWord("large");
    return 0;
}