/* Your program should accept exactly three command-line arguments, whereby the first (n) must be a positive integer less than or equal to 100,
the second must be the name of a BMP to be resized, and the third must be the name of the resized version to be written.
If your program is not executed with such, it should remind the user of correct usage, as with fprintf (to stderr), and main should return 1. */

// Code from copy.c

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    long n = atoi(argv[1]);

    if (n < 1 || n > 100)
    {
        fprintf(stderr, "the resize factor must be a positive number between 1 and 100\n");
    }

    // remember filenames
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

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    BITMAPFILEHEADER bf_new;
    BITMAPINFOHEADER bi_new;

    bf_new = bf;
    bi_new = bi;

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Multiply the width and the height by the scale factor
    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;

    // determine padding for previous and new scanlines
    int new_padding = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // The size of the image is width * height, and the size of the whole file is the image size + the header
    bi_new.biSizeImage = (bi_new.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi_new.biHeight);
    bf_new.bfSize = sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER) + bi_new.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // provide memory for the new array
    RGBTRIPLE *new_array = malloc(sizeof(RGBTRIPLE) * bi_new.biWidth);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Set a counter value
        int count = 0;

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
             RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //write the triple to the new array
            for (int k = 0; k < n; k++)
            {
                *(new_array + count) = triple;
                count++;
            }


            fseek(inptr, padding, SEEK_CUR);

            //write the new array to the outfile
            for (int m = 0; m < n; m++)
            {
                fwrite(new_array, sizeof(RGBTRIPLE), bi.biWidth, outptr);

                //add new padding
                for (int p = 0; p < new_padding; p++)
                {
                    fputc(0x00, outptr);
                }
            }
        }
    }

    free(new_array);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}