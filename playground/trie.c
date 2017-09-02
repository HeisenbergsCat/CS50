#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trie.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("need some args!");
        return 1;
    }

    DICT_TRIE *root = malloc(sizeof(DICT_TRIE));

    addWords(&root, "large");
    int check = wordCheck(root, argv[1]);

    //printf("wordcount: %i", root -> wordcount);
    printf("\ncheck: %i\n", check);

    //destroyTrie(root);
    return 0;
}
int charToIndex(char letter)
{
    if(letter == '\'')
    {
        return (int)letter - 39;
    }
    return (int)letter - 96;
}

DICT_TRIE *wordInsert(DICT_TRIE *root, char *word)
{
    DICT_TRIE *cursor = root;
    DICT_TRIE *start = root;

    //iterate through given word
    for(int i = 0; i < strlen(word); i ++)
    {
        //calculate index for current character
        int charIndex = charToIndex(word[i]);

        //if there's no pointer assigned to curretn index, malloc a new node and advance the traversing pointer
        if (cursor -> children[charIndex] == NULL) {

            DICT_TRIE *node;
            node = malloc(sizeof(DICT_TRIE));
            cursor -> children[charIndex] = node;
            cursor = node;
        }
        //if there's already a pointer in the current index, move on
        else if (cursor -> children[charIndex] != NULL)
        {
            cursor = cursor ->children[charIndex];
        }

    }
    cursor -> isword = true;
    start -> wordcount ++;
    return start;
}

int wordCheck(DICT_TRIE *root, char *word)
{
    DICT_TRIE *cursor = root;

    //iterate through given word
    for(int i = 0; i < strlen(word); i ++)
    {
        //calculate index for current character
        int charIndex = charToIndex(word[i]);

        if (cursor -> children[charIndex] == NULL)
        {
            return 0;
        }
        else if (cursor -> children[charIndex] != NULL)
        {
            cursor = cursor ->children[charIndex];
        }
    }

    if (cursor -> isword == true)
    {
        return 1;
    }

    return 0;
}

void printNode(DICT_TRIE *node)
{
    DICT_TRIE *cursor = node;

        for (int i = 0; i < 27; i ++)
        {
            if (cursor -> children[i] != NULL) {
                printf("%c", i + 96);
            }
            else
            {
                printf (".");
            }
        }
        printf("\n");
}

void addWords(DICT_TRIE **root, char *filename)
{
    FILE *testFile;
    testFile = fopen(filename, "r");

    if (!testFile)
    {
        printf("LOADING ERROR!");
    }

    char buffer[45 * sizeof(char)];

    while (fscanf(testFile, "%s", buffer) == 1)
    {
        wordInsert(*root, buffer);
        //printf("%i: %s \n", index, buffer);
    }

    fclose(testFile);
}

void destroyTrie(DICT_TRIE *root)
{
    DICT_TRIE *cursor = root;
    int index = 0;

    while (cursor -> children[index] != NULL)
    {
        if (cursor -> children[index] == NULL)
        {
            destroyTrie(cursor);
            index ++;
        }
    }
}



