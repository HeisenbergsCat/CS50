#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipherThat(string plainText, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("no arguments, no fun :( \n");
        return 1;
    }
    
    int k;
    k = atoi(argv[1]);
    
    if (k >= 25)
    {
        k = k % 26;
    }
    
    printf("plaintext:");
    string plainText = get_string();
    
    printf("ciphertext:");
    cipherThat(plainText, k);
    
    printf("\n");
    
    
return 0;
}

void cipherThat(string plainText, int k) {
        
        for (int character = 0; character < strlen(plainText); character ++)
        {
            int aChar = (int)plainText[character];
            
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
                printf("%c",plainText[character]);
            }
         
        }
            
    }