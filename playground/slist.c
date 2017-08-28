#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DATA STRUCTURES
typedef struct _NODE_STR
{
    char *item;
    struct _NODE_STR *next;
}
NODE_STR;

//functions definitions
NODE_STR *createNew(char* element);
NODE_STR *insertFirst(NODE_STR *head, char *element);
NODE_STR *insertAfter(NODE_STR *head, char *element, char *input);
NODE_STR *insertLast(NODE_STR *head, char *element);

char *listSearch(NODE_STR *head, char* text);
void printList(NODE_STR *head);
void destroy(NODE_STR *head);

//MAIN
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: linkedTest First_item\n");
        return 1;
    }

    //create a pointer to first node in the list with data given by user input
    NODE_STR *newlist = createNew(argv[1]);

    if (newlist != NULL)
    {
        //insert some more element to the list
        newlist = insertLast(newlist, "1_drumsticks");
        newlist = insertLast(newlist, "2_bass");
        newlist = insertLast(newlist, "3_headphones");

        //test inserting last element
        //ewlist = insertLast(newlist, "LastItem");

        //test inserting middle element
        //newlist = insertAfter(newlist, "1_drumsticks", "HEADS");

        //print the entire list
        printList(newlist);
        printf("\n");

        //test search function
        printf("found %s\n\n", listSearch(newlist, "LastItem"));

        destroy(newlist);
    }
    else
    {
        return 1;
    }
    return 0;
} // END OF MAIN


//FUNCTION DECLARATIONS

//creates first node of the list
//returns new head pointer
NODE_STR *createNew(char *element)
{
    NODE_STR *node;
    node = malloc(sizeof(NODE_STR));

    if (node != NULL)
    {
        node -> item = element;
        node -> next = NULL;
    }
    return node;
}

//creates new node with passet item and puts it at the start of the list
//returns new head pointer
NODE_STR *insertFirst(NODE_STR *head, char *element)
{
    NODE_STR *ptr = head;
    NODE_STR *newNode;
    newNode = malloc(sizeof(NODE_STR));

    if (newNode != NULL)
    {
        newNode -> item = element;
        newNode -> next = ptr;
        ptr = newNode;
    }
    return ptr;
}

//adds new node at the end of the list
//returns pointer to the start of the list
NODE_STR *insertLast(NODE_STR *head, char *element)
{
    NODE_STR *ptr = head;
    NODE_STR *start = head;
    NODE_STR *newNode;
    newNode = malloc(sizeof(NODE_STR));

    if (newNode != NULL)
    {
        newNode -> item = element;
        while (ptr != NULL)
        {
            if (ptr -> next == NULL)
            {
                ptr -> next = newNode;
                newNode -> next = NULL;
            }
            ptr = ptr -> next;
        }
        ptr = start;
    }
    return ptr;
}

//creates new node after another node with passed element
//returns pointer to the head of the list
NODE_STR *insertAfter(NODE_STR *head, char *searchedEl, char *input)
{
    NODE_STR *ptr = head;
    NODE_STR *start = head;
    NODE_STR *newNode;

    newNode = malloc(sizeof(NODE_STR));

    if (newNode != NULL)
    {
        newNode -> item = input;
        while (ptr != NULL)
        {
            if (ptr -> item == searchedEl)
            {
                newNode -> next = ptr -> next;
                ptr -> next = newNode;
            }
            ptr = ptr ->next;
        }
        ptr = start;
    }
    return ptr;
}

//searches the list's items for given string input
//returns item if found, returns "nothing" if not found
char* listSearch(NODE_STR *head, char* text)
{
    NODE_STR *ptr = head;
    while (ptr != NULL)
    {
        if(strcmp(ptr -> item, text) == 0)
        {
            return ptr -> item;
            break;
        }
        ptr = ptr -> next;

        if (ptr == NULL)
        {
           return "nothing";
        }
    }
    return "";
}

//frees the memory allocated for the list
void destroy(NODE_STR *head)
{
    NODE_STR *ptr = head;
    NODE_STR *nextone;

    while (ptr != NULL)
    {
        nextone = ptr -> next;
        free(ptr);
        ptr = nextone;
    }

    printf("list deleted!\n");
}

//prints every item of the list
void printList(NODE_STR *head)
{
    NODE_STR *ptr = head;

    while (ptr != NULL) {
        printf("%s\n", ptr -> item);
        ptr = ptr -> next;
    }
}