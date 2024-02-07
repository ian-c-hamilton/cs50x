#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Rename uint8 to BYTE for ease of use
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover [file.raw]\n");
        return 1;
    }

    // Open file in read mode
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Create the block that data will be read into
    BYTE block[512];
    // Create a buffer for the names of the files to be saved to
    char buffer[8];
    // Initialize the file numbers from zero
    int fileno = 0;
    // Create an outut file point for use in the while loop
    FILE *output = NULL;
    // Read card until can't anymore
    while (fread(&block, sizeof(BYTE) * 512, 1, file))
    {
        // Check the requirements for the start of a jpeg file
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // If not the first file, close the previous one
            if (!(fileno == 0))
            {
                fclose(output);
            }
            // Use sprintf to format the file name
            sprintf(buffer, "%03i.jpg", fileno);
            output = fopen(buffer, "w");
            fileno++;
        }
        // If we found a file, keep writing 512 bytes at a time until we find the next one the the condition at the beginning of the while loop
        if (!(fileno == 0))
        {
            fwrite(block, 512, 1, output);
        }
    }
    fclose(output);
    fclose(file);

}