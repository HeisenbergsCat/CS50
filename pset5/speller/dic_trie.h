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

//Converts character to a proper array index
int charToIndex(char letter);

//Inserts a single word to a trie data structure
void wordInsert(DICT_TRIE **root, char *word);

//Checks if a word is in a trie data structure
bool wordCheck(DICT_TRIE *root, const char *word);

//Prints children of a single trie node
void printNode(DICT_TRIE **root);

//Adds words from a file to a trie
bool addWords(DICT_TRIE **root, const char *filename);

//unloads all trie's nodes from memory
//Return true if succeded, false otherwise
bool destroyNode (DICT_TRIE **node);

//prints whole tree structure
void printTrie (DICT_TRIE **node);