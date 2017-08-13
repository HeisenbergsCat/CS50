/*
CS50 Problem set 2: Caesar, less comfortable
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void cipherThat(string plainText, int k);

int main(int argc, string argv[])
{
    //checks proper usage
    if (argc != 2)
    {
        printf("no arguments, no fun :( \n");
        return 1;
    }

    //saves users argument
    int k;
    k = atoi(argv[1]);

    //when out of bounds, reset to the proper position
    if (k >= 25)
    {
        k = k % 26;
    }

    //gets text to be ciphered
    printf("plaintext:");
    string plainText = get_string();

    //prints ciphered text
    printf("ciphertext:");
    cipherThat(plainText, k);

    printf("\n");

    return 0;
}

//ciphers given plainText using caesar cipher by k characters
void cipherThat(string plainText, int k)
{

    //loops thru given plainText
    for (int character = 0; character < strlen(plainText); character ++)
    {
        //saves iterated character as an ASCII number
        int aChar = (int)plainText[character];

        //for uppercase
        if (aChar >= 97 && aChar <= 122)
        {
            if (aChar + k >= 122 )
            {
                printf("%c", (char) 96 + (k - (122 - aChar)));
            }
            else
            {
                printf("%c", (char)aChar + k);
            }
        }
        //for lowercase
        else if (aChar >= 65 && aChar <= 90)
        {
            if (aChar + k >= 90 )
            {
                printf("%c", (char) 64 + (k - (90 - aChar)));
            }
            else
            {
                printf("%c", (char)aChar + k);
            }
        }
        else
        {
            printf("%c", plainText[character]);
        }
    }
}