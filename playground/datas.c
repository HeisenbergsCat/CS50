#include <stdio.h>

typedef struct TESTCHAR
{
    char a;
    char b;
    char c;
} 
TESTCHAR;

int main() {
    
    TESTCHAR test;
    TESTCHAR *ptr = &test;
    
    FILE *outfile = fopen("test.txt", "w");
    
    ptr -> a = 'a';
    ptr -> b = 'x';
    ptr -> c = 'z';
    printf("%c, %c, %c", ptr -> a, ptr -> b, ptr -> c);
    
    for (int i = 0; i < sizeof(TESTCHAR); i++)
    {
        fwrite(ptr, sizeof(char), 1, outfile);
        fseek(outfile, sizeof(char), SEEK_CUR);
    }
    
    fclose(outfile);
    return 0;
}