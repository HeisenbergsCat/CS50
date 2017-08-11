/**
 * resizes bmp of a given factor
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    float factor = atof(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    BITMAPFILEHEADER newBF;
    newBF = bf;
    
    BITMAPINFOHEADER newBI;
    newBI = bi;
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    //update headers for rescaled image
    newBI.biWidth = bi.biWidth * factor;
    newBI.biHeight = bi.biHeight * factor;
    int newPadding = (4 - (newBI.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    newBI.biSizeImage = ((sizeof(RGBTRIPLE) * newBI.biWidth) + newPadding) * abs(newBI.biHeight);
    newBF.bfSize = newBI.biSizeImage  + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&newBF, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&newBI, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    
    RGBTRIPLE pixels[abs(bi.biHeight)][bi.biWidth];
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {

            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            pixels[i][j] = triple;
            
        }
        
        fseek(inptr, oldPadding, SEEK_CUR);

    }
    if(factor >= 1)
    {
       for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            for(int y = 0; y < factor; y++)
            {
                for (int j = 0; j < bi.biWidth; j++)
                {
                    for(int x = 0; x < factor; x++)
                    {
                        fwrite(&pixels[i][j], sizeof(RGBTRIPLE), 1, outptr); 
                    }
                }
                
                for (int k = 0; k < newPadding; k++)
                {
                    fputc(0x00, outptr);
                }
                
            }
    
        } 
    } 
    else 
    {
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i += 1/factor)
        {
                for (int j = 0; j < bi.biWidth; j += 1/factor)
                {
                        fwrite(&pixels[i][j], sizeof(RGBTRIPLE), 1, outptr);
                }
                
                for (int k = 0; k < newPadding; k++)
                {
                    fputc(0x00, outptr);
                }
    
        }
    }
    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
