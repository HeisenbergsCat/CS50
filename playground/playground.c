#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "zuo");
        return 1;
    }
    
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    
    printf("%i", i + j );
    printf("\n");
}