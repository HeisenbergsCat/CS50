#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "trie.h"

int main() {
    /*
    if (argc != 2) {
        printf("need some args!");
        return 1;
    }*/

    DICT_TRIE *root = malloc(sizeof(DICT_TRIE));

    //ROOT INITIALIZATION

    root -> isword = false;
    root -> wordcount = 0;
    for (int i = 0; i < 27; i ++)
    {
        root -> children[i] = NULL;
    }

    addWords(&root, "small");

    bool check = wordCheck(root, "satan");

    printf("wordcount: %i", root -> wordcount);
    printf("\ncheck: %s\n", check ? "true" : "false");
    destroyNode(&root);

    return 0;
}

//Converts character to a proper array index
int charToIndex(char letter)
{
    if(letter == '\'')
    {
        return 0;
    }
    return (int)letter - 96;
}

//Inserts a single word to a trie data structure
void wordInsert(DICT_TRIE **root, char *word)
{
    DICT_TRIE *cursor = *root;
    DICT_TRIE *start = *root;

    //iterate through given word
        for (int i = 0; i < strlen(word); i++)
        {
            //calculate index for current character
            int charIndex = charToIndex(tolower(word[i]));

            //if there's already a pointer in the current index, move on
            if (cursor -> children[charIndex] != NULL)
            {
                cursor = cursor ->children[charIndex];
            }
            //if there's no pointer assigned to curretn index, malloc a new node and advance the traversing pointer
            if (cursor -> children[charIndex] == NULL) {

                DICT_TRIE *node;
                node = malloc(sizeof(DICT_TRIE));

                //NODE INITIALIZATION
                for (int j = 0; j < 27; j++)
                {
                    node -> children[j] = NULL;
                }

                cursor -> children[charIndex] = node;
                cursor = node;
            }

    }
    cursor -> isword = true;
    start -> wordcount ++;
}

//Checks if a word is in a trie data structure
//Returns true if found, return false if not
bool wordCheck(DICT_TRIE *root, char *word)
{
    DICT_TRIE *cursor = root;
    DICT_TRIE *copy = root;
    //calculate index for current character
    //iterate through given word
    for(int i = 0; i < strlen(word) ; i ++)
    {
        int charIndex = charToIndex(tolower(word[i]));
        if (cursor -> children[charIndex] == NULL)
        {
            return false;
        }

        if (cursor -> children[charIndex] != NULL)
        {
            cursor = cursor ->children[charIndex];
            copy = cursor;
        }
    }
    return copy -> isword;
}

//Prints children of a single trie node
void printNode(DICT_TRIE **node)
{
    DICT_TRIE *cursor = *node;

        for (int i = 0; i < 27; i ++)
        {
            if (cursor -> children[i] != NULL) {
                printf("%c", i + 96);
                if (cursor -> children[i] -> isword == true) { printf("*"); }
            }
            else
            {
                printf (".");
            }
        }
        printf("\n");
}

//Adds words from a file to a trie
//Return true if succeded, otherwise return false
bool addWords(DICT_TRIE **root, char *filename)
{
    FILE *testFile;
    testFile = fopen(filename, "r");

    if (!testFile)
    {
        printf("LOADING ERROR!");
        return false;
    }

    char buffer[45 * sizeof(char)];

    while (fscanf(testFile, "%s", buffer) == 1)
    {
        wordInsert(root, buffer);
    }
    fclose(testFile);
    return true;

}

//unloads all trie's nodes from memory
//Return true if succeded, false otherwise
bool destroyNode (DICT_TRIE **node)
{
    DICT_TRIE *cursor = *node;
    if (!cursor) { return false; }

    int i;
    for (i = 0; i < 27; i ++)
    {
        if (cursor -> children[i] != NULL)
        {
            destroyNode(&cursor -> children[i]);
        }
    }
    free(cursor);
    return true;
}

//prints whole tree structure
void printTrie (DICT_TRIE **node)
{
    DICT_TRIE *cursor = *node;
    printNode(&cursor);

    int i;
    for (i = 0; i < 27; i ++)
    {
        if (cursor -> children[i] != NULL)
        {
            printTrie(&cursor -> children[i]);
        }
    }
}



