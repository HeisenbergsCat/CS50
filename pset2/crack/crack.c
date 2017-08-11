#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("no arguments, no fun :( \n");
        return 1;
    }
    
    
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

    
    char* guess1;
    guess1 = malloc(2);
    
    char* guess2;
    guess2 = malloc(3);
    
    char* guess3;
    guess3 = malloc(4);
    
    char* guess4;
    guess4 = malloc(5);
    
    
    //search 1 letter password
    
    for (int q = 0; q < 52; q++)
    {
        guess1[0] = lettersLibrary[q];
                
        if (strcmp(crypt(guess1, "50"), argv[1]) == 0)
            {
                printf("FOUND IT!\n");
                printf("Password is: %s\n", guess1);
                return 0;
                break;
            }   
    }
    
    printf("now searching 2 letter password...\n");
    //search 2 letter password    
    
    for (int q = 0; q < 52; q++)
    {
        for (int w = 0; w < 52; w++)
            {
                guess2[0] = lettersLibrary[q];
                guess2[1] = lettersLibrary[w];
                        
                if (strcmp(crypt(guess2, "50"), argv[1]) == 0)
                    {
                        printf("FOUND IT!\n");
                        printf("Password is: %s\n", guess2);
                        return 0;
                        break;
                                
                    }
            }
    }
    
    printf("now searching 3 letter password...\n");
    //search 3 letter password  
    
    for (int q = 0; q < 52; q++)
    {
        for (int w = 0; w < 52; w++)
            {
                for (int e = 0; e < 52; e++)
                    {
                        guess3[0] = lettersLibrary[q];
                        guess3[1] = lettersLibrary[w];
                        guess3[2] = lettersLibrary[e];
                                
                        if (strcmp(crypt(guess3, "50"), argv[1]) == 0)
                            {
                                printf("FOUND IT!\n");
                                printf("Password is: %s\n", guess3);
                                return 0;
                                break;
                                        
                            }
                    }
            }
    }
    
    printf("now searching 4 letter password...\n");
    //search 4 letter password  
               
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
                                
                                if (strcmp(crypt(guess4, "50"), argv[1]) == 0)
                                    {
                                        printf("FOUND IT!\n");
                                        printf("Password is: %s\n", guess4);
                                        return 0;
                                        break;
                                        
                                    }
                             }
                    }
            }
    }
}