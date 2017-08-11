#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    char lettersLibrary[95];
    int asciiChar = 33;
    
    for (int i = 0; i < 95; i ++)
    {
        
        lettersLibrary[i] = (char)asciiChar;
        asciiChar++;
        /*
        if (asciiChar == 91)
        {
            asciiChar = 97;
        }
        */
        
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
    
    for (int q = 0; q < 95; q++)
    {
        guess1[0] = lettersLibrary[q];
                
        printf("%s\n", guess1);  
    }
    
    //printf("now searching 2 letter password...\n");
    //search 2 letter password    
    
    for (int q = 0; q < 95; q++)
    {
        for (int w = 0; w < 95; w++)
            {
                guess2[0] = lettersLibrary[q];
                guess2[1] = lettersLibrary[w];
                        
                printf("%s\n", guess2);
                
            }
    }
    
    //printf("now searching 3 letter password...\n");
    //search 3 letter password  
    
    for (int q = 0; q < 95; q++)
    {
        for (int w = 0; w < 95; w++)
            {
                for (int e = 0; e < 95; e++)
                    {
                        guess3[0] = lettersLibrary[q];
                        guess3[1] = lettersLibrary[w];
                        guess3[2] = lettersLibrary[e];
                                
                        printf("%s\n", guess3);
                    }
            }
    }
    
    //printf("now searching 4 letter password...\n");
    //search 4 letter password  
               
    for (int q = 0; q < 95; q++)
    {
    
        for (int w = 0; w < 95; w++)
            {

                for (int e = 0; e < 95; e++)
                    {

                        for (int r = 0; r < 95; r++)
                            {
 
                                guess4[0] = lettersLibrary[q];
                                guess4[1] = lettersLibrary[w];
                                guess4[2] = lettersLibrary[e];
                                guess4[3] = lettersLibrary[r];
                                
                                printf("%s\n", guess4);
                             }
                    }
            }
    }
}