/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"
#include "dic_trie.h"

DICT_TRIE *dictTrie;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    return wordCheck(dictTrie, word);
    //return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    dictTrie = malloc(sizeof(DICT_TRIE));

    for (int i = 0; i < 27; i ++)
    {
        dictTrie -> children[i] = NULL;
    }
    dictTrie -> isword = false;
    dictTrie -> wordcount = 0;

    return addWords(&dictTrie, dictionary);
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictTrie -> wordcount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return destroyNode(&dictTrie);
    //return false;
}
