#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//DATA STRUCTURES
typedef struct _trie
{
    bool isword;
    int wordcount;
    struct _trie *children[27];
}
DICT_TRIE;

//FUNCTION DECLARATIONS
DICT_TRIE *wordInsert(DICT_TRIE *root, char *word);
int charToIndex(char letter);
int wordCheck(DICT_TRIE *root, char *word);
void printNode(DICT_TRIE *root);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("need some args!");
        return 1;
    }

    DICT_TRIE *root = malloc(sizeof(DICT_TRIE));
    root = wordInsert(root, "sexy");
    root = wordInsert(root, "devil");
    root = wordInsert(root, "sex");
    root = wordInsert(root, "debil");
    root = wordInsert(root, "lupa");
    root = wordInsert(root, "dupa");
    root = wordInsert(root, "avocado");
    root = wordInsert(root, "'trash");
    root = wordInsert(root, "zenon");
    root = wordInsert(root, "cleco'");
    root = wordInsert(root, "but");
    root = wordInsert(root, "awangarda");

    printNode(root -> children[1]);

    int check = wordCheck(root, argv[1]);
    printf("wordcount: %i", root -> wordcount);
    printf("\ncheck: %i\n", check);

    return 0;
}

//FUNCION DEFINITIONS

int charToIndex(char letter)
{
    if(letter == '\'')
    {
        return (int)letter - 39;
    }
    return (int)letter - 96;
}

//INSERT A WORD IN THE DATA STRUCTURE
DICT_TRIE *wordInsert(DICT_TRIE *root, char *word)
{
    DICT_TRIE *ptr = root;
    DICT_TRIE *start = root;

    //iterate through given word
    for(int i = 0; i < strlen(word); i ++)
    {
        //calculate index for current character
        int charIndex = charToIndex(word[i]);

        //if there's no pointer assigned to curretn index, malloc a new node and advance the traversing pointer
        if (ptr -> children[charIndex] == NULL) {

            DICT_TRIE *node = malloc(sizeof(DICT_TRIE));
            ptr -> children[charIndex] = node;
            ptr = node;
        }
        //if there's already a pointer in the current index, move on
        else if (ptr -> children[charIndex] != NULL)
        {
            ptr = ptr ->children[charIndex];
        }

    }
    ptr -> isword = true;
    start -> wordcount ++;
    return start;
}

//CHECK IF A WORD IS IN DATA STRUCTURE
int wordCheck(DICT_TRIE *root, char *word)
{
    DICT_TRIE *ptr = root;

    //iterate through given word
    for(int i = 0; i < strlen(word); i ++)
    {
        //calculate index for current character
        int charIndex = charToIndex(word[i]);

        if (ptr -> children[charIndex] == NULL)
        {
            return 0;
        }
        else if (ptr -> children[charIndex] != NULL)
        {
            ptr = ptr ->children[charIndex];
        }
    }

    if (ptr -> isword == true)
    {
        return 1;
    }

    return 0;
}

//PRINT A SINGLE NODE
void printNode(DICT_TRIE *node)
{
    DICT_TRIE *ptr = node;

        for (int i = 0; i < 27; i ++)
        {
            if (ptr -> children[i] != NULL) {
                printf("%c", i + 96);
            }
            else
            {
                printf (".");
            }
        }
        printf("\n");
}



