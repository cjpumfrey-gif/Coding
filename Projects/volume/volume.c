// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    // Open file for regading in binary mode "rb"
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file. %s \n", argv[1]);
        return 1;
    }
    // we need to open this in writing binary mode
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file. %s.\n", argv[2]);
        fclose(input);
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    uint8_t header[HEADER_SIZE];

    // TODO: Read samples from input file and write updated data to output file
    if (fread(header, sizeof(uint8_t), HEADER_SIZE, input) != HEADER_SIZE)
    {
        printf("Error reading header from %s.\n", argv[1]);
        fclose(input);
        fclose(output);
        return 1;
    }

    if (fwrite(header, sizeof(uint8_t), HEADER_SIZE, output) != HEADER_SIZE)
    {
        printf("Error writing header to %s.\n", argv[2]);
        fclose(input);
        fclose(output);
        return 1;
    }

    // read samples one at a time
    // we read 1 element of size (int16_t)
    int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        float scaled_value = sample * factor;
        int16_t scaled_sample = (int16_t) scaled_value;
        if (fwrite(&scaled_sample, sizeof(int16_t), 1, output) != 1)
        {
            printf("Error writing sample to %s.\n", argv[2]);
            fclose(input);
            fclose(output);
            return 1;
        }
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}
