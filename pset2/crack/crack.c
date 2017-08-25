/*
CS50 Problem set 2: Crack, more comfortable
TOFO: Write a hasher to make some example passwords
TODO: Make it with recursion
TODO: Make number of characters as argv
TODO: Make salt as argv
TODO: Different hashing alghoritms
*/

#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //check proper usage
    if (argc != 2)
    {
        printf("no arguments, no fun :( \n");
        return 1;
    }

    //generates aaray of possible characters
    char lettersLibrary[52];
    int asciiChar = 65;

    for (int i = 0; i < 52; i ++)
    {

        lettersLibrary[i] = (char)asciiChar;
        asciiChar++;

        if (asciiChar == 91)
        {
            asciiChar = 97;
        }
    }

    //search 1 letter password

    //allocates memory for 1 letter password
    char *guess1;
    guess1 = malloc(2);

    //generates all possible combinations of 1 character string
    if (guess1) //sanity check
    {
        for (int q = 0; q < 52; q++)
        {
            guess1[0] = lettersLibrary[q];

            //hash the guess and comapre to the hash user provided
            if (strcmp(crypt(guess1, "50"), argv[1]) == 0)
            {
                //prompt found password
                printf("FOUND IT!\n");
                printf("Password is: %s\n", guess1);
                free(guess1);
                return 0;
                break;
            }
        }
    }

    printf("now searching 2 letter password...\n");
    //search 2 letter password

    //allocates memory for 2 letter password
    char *guess2;
    guess2 = malloc(3);

    //generates all possible combinations of 2 character string
    if (guess2)
    {
        for (int q = 0; q < 52; q++)
        {
            for (int w = 0; w < 52; w++)
            {
                guess2[0] = lettersLibrary[q];
                guess2[1] = lettersLibrary[w];

                //hash the guess and comapre to the hash user provided
                if (strcmp(crypt(guess2, "50"), argv[1]) == 0)
                {
                    //prompt found password
                    printf("FOUND IT!\n");
                    printf("Password is: %s\n", guess2);
                    free(guess1);
                    free(guess2);
                    return 0;
                    break;

                }
            }
        }
    }

    printf("now searching 3 letter password...\n");
    //search 3 letter password

    //allocates memory for 3 letter password
    char *guess3;
    guess3 = malloc(4);

    //generates all possible combinations of 3 character string
    if (guess3)
    {
        for (int q = 0; q < 52; q++)
        {
            for (int w = 0; w < 52; w++)
            {
                for (int e = 0; e < 52; e++)
                {
                    guess3[0] = lettersLibrary[q];
                    guess3[1] = lettersLibrary[w];
                    guess3[2] = lettersLibrary[e];

                    //hash the guess and comapre to the hash user provided
                    if (strcmp(crypt(guess3, "50"), argv[1]) == 0)
                    {
                        //prompt found password
                        printf("FOUND IT!\n");
                        printf("Password is: %s\n", guess3);
                        free(guess1);
                        free(guess2);
                        free(guess3);
                        return 0;
                        break;

                    }
                }
            }
        }
    }

    printf("now searching 4 letter password...\n");
    //search 4 letter password

    //allocates memory for 4 letter password
    char *guess4;
    guess4 = malloc(5);

    //generates all possible combinations of 4 character string
    if (guess4)
    {
        for (int q = 0; q < 52; q++)
        {
            for (int w = 0; w < 52; w++)
            {
                for (int e = 0; e < 52; e++)
                {
                    for (int r = 0; r < 52; r++)
                    {
                        guess4[0] = lettersLibrary[q];
                        guess4[1] = lettersLibrary[w];
                        guess4[2] = lettersLibrary[e];
                        guess4[3] = lettersLibrary[r];

                        //hash the guess and comapre to the hash user provided
                        if (strcmp(crypt(guess4, "50"), argv[1]) == 0)
                        {
                            //prompt found password
                            printf("FOUND IT!\n");
                            printf("Password is: %s\n", guess4);
                            free(guess1);
                            free(guess2);
                            free(guess3);
                            free(guess4);
                            return 0;
                            break;

                        }
                    }
                }
            }
        }
    }
}