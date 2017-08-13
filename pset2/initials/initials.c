/*
CS50 Problem set 2: Initials, more comfortable
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //gets name from the user
    string user_name = get_string();

    if (user_name != NULL)
    {
        //sets buffer character
        char temp_letter = ' ';

        //iterates thru user typed string
        for (int letter = 0; letter < strlen(user_name); letter++ )
        {
            //if last letter was space and current letter isn't
            if ((int)temp_letter == 32 && (int)user_name[letter] != 32)
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