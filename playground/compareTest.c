#define _XOPEN_SOURCE 600
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("no arguments, no fun :( \n");
        return 1;
    }
    
    char *plainText = "rofl";
    char *hashedText = crypt(plainText, "50");
    char *argumentHash = argv[1];
    
    //printf("%s -> %s -> %s", plainText, hashedText, argumentHash);

    if (strcmp(hashedText, argumentHash) == 0)
        {
            printf("FOUND IT!");
        } 
        else 
        { 
            printf(":(");
        }
        
}