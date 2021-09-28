#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Make sure the user gives two inputes including the filename
    if (argc > 2)
    {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }

    // Create a buffer to read bytes to that from the raw file
    uint8_t buffer[512];

    // Open the raw file to read the bytes
    FILE *rawfile = fopen(argv[1], "r");

    if (!rawfile)
    {
        printf("Not enough memory to open the file.\n");
        return 1;
    }

    // Create an output file pointer
    FILE *outfile = NULL;

    // Create an array to store the output file names
    char filename[8];
    filename[7] = '\0';

    // Keep track of files created
    int fileno = 0;

    // Keep track of valid writes to the buffer
    int bufferrwrites = 0;

    // Create new jpegs from the raw file
    while (fread(&buffer, 1, 512, rawfile) == 512)
    {
        // Check if the current block start with a jpeg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Create new jpeg file and write to that file
            sprintf(filename, "%03i.jpg", fileno);
            fileno++;

            outfile = fopen(filename, "w");
            fwrite(&buffer, 1, 512, outfile);

            bufferrwrites++;
        }
        // If the current block isn't a beginning of a jpeg then keep writing the current flie
        else if (bufferrwrites > 0)
        {
            fwrite(&buffer, 1, 512, outfile);
        }
    }

    return 0;
}
