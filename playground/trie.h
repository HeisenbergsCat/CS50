#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DATA STRUCTURES
typedef struct _trie
{
    bool isword;
    int wordcount;
    struct _trie *children[27];
}
DICT_TRIE;

//Inserts a word to a trie data structure
DICT_TRIE *wordInsert(DICT_TRIE *root, char *word);

//Converts character to a proper array index
int charToIndex(char letter);

//Checks if a word is in a trie data structure
int wordCheck(DICT_TRIE *root, char *word);

//Prints children of a single trie node
void printNode(DICT_TRIE *root);

//Adds words from a file to a trie
void addWords(DICT_TRIE **root, char *filename);

//unloads all trie's nodes from memory
void destroyTrie(DICT_TRIE *root);
