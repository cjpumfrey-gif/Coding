#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define the block size of the FAT file system
const int BLOCK_SIZE = 512;

// Define a type for a byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // 1. Check command-line arguments
    // The program should accept exactly one argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // 2. Open the forensic image (input file)
    // Open in "read binary" ("rb") mode
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // 3. Set up variables for recovery
    BYTE buffer[BLOCK_SIZE]; // A buffer to store one 512-byte block
    int file_counter = 0;    // Counter for JPEG filenames (000, 001, ...)
    FILE *output_file = NULL; // Pointer for the current output JPEG file
    char filename[8];        // String to hold the filename (e.g., "000.jpg\0")


    while (fread(buffer, 1, BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // Check for the JPEG signature at the start of the block
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Found the start of a new JPEG!

            // First, if a JPEG file is already open, close it.
            if (output_file != NULL)
            {
                fclose(output_file);
            }

          
            sprintf(filename, "%03i.jpg", file_counter);

            // Open the new output file in "write binary" ("wb") mode
            output_file = fopen(filename, "wb");
            if (output_file == NULL)
            {
                // If we can't create the file, clean up and exit
                printf("Could not create %s.\n", filename);
                fclose(input_file);
                return 1;
            }

            // Increment the file counter for the next JPEG
            file_counter++;
        }


        if (output_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output_file);
        }
    }


    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Close th input file
    fclose(input_file);

    // Success
    return 0;
}
