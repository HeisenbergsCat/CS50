/**
 * CS50x, Problemset 4, Recover jpgs from memory card image
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{

    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover disk_image\n" );
        return 1;
    }

    //save file name
    char *infile = argv[1];

    //open card image file for read
    FILE *inptr = fopen(infile, "r");


    //check if the file exists
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s/n", infile);
    }

    //allocate memory for one block
    BYTE *buffer;
    buffer = malloc(sizeof(buffer) * 512);

    //initialize variable to check if there's alreade file been written
    int jpgActive = 0;
    //initialize variable to iterate over file name
    int nameCount = 0;

    //initialize string to store file name
    char *filename;
    filename = malloc(sizeof(char) * 3);

    //open initial file
    FILE *outptr = fopen("000.jpg", "w");

    //loop over data and read each block
    while (fread(buffer, 512, 1, inptr))
    {
        //when encounter JPG signatures
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if there's already file beign written, close that file
            if (jpgActive == 1)
            {
                fclose(outptr);
            }

            //update file nam with iterator
            sprintf(filename, "%03i.jpg", nameCount);

            //open new file, for the next jpg
            outptr = fopen(filename, "w");

            //iterate file name counter
            nameCount += 1;


            jpgActive = 1;

        }

        if (jpgActive == 1)
        {
            fwrite(buffer, 512, 1, outptr);
        }

    }

    free(buffer);
    free(filename);
    fclose(outptr);
    fclose(inptr);
    return 0;
}
