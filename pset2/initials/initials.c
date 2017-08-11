#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) 
{
string user_name = get_string();

if (user_name != NULL) 
{
    char temp_letter = ' ';
    for(int letter = 0; letter < strlen(user_name); letter++ )
    {
        if((int)temp_letter == 32 && (int)user_name[letter] != 32)
        {
            temp_letter = user_name[letter];
            printf("%c", toupper(user_name[letter]));
        } 
        else 
        {
             temp_letter = user_name[letter];
        }
        
    }
    
}

printf("\n");

return 0;   
}