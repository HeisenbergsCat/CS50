#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    FILE *dict;
    char buffer[5];
    
    dict = fopen("azUpperLower.txt", "r");
    
    
    while (!feof(dict))
    {
    fgets(buffer, sizeof(buffer), (FILE*)dict);
    printf("%s", buffer);
    }
    
    
    fclose(dict);
    
    return 0;
}
