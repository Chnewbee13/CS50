#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover [image name]\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // check file opened properly and exit if not
    if (card == NULL)
    {
        fclose(card);
        printf("Could not open file\n");
        return 1;
    }

    // set size of blocks of bytes to 512
    int block = 512;

    // create a buffer of 521 bytes
    BYTE buffer[block];

    // create a string to store filenames
    char filename[8] = {0};

    // set JPEG counter to 0
    int jpeg = 0;

    // create pointer for output JPEG
    FILE *IMG = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, sizeof(BYTE) * block, card) == 512)
    {
        // if JPEG found
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // if not first JPEG found, close previously opened IMG
            if (jpeg > 0)
            {
                fclose(IMG);
            }

            // open a new file for writing with name 000.jpg (and counting)
            sprintf(filename, "%03i.jpg", jpeg++);
            IMG = fopen(filename, "w");

            // fill IMG with bytes from memory card
            fwrite(buffer, 1, sizeof(BYTE) * block, IMG);
        }

        // else if not the start of a new JPEG, continue writing to previous IMG
        else if (jpeg > 0)
        {
            fwrite(buffer, 1, sizeof(BYTE) * block, IMG);
        }
    }

    fclose(IMG);
    fclose(card);

    return 0;
}
