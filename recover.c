#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //Check argument count is 2
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open the file for reading
    FILE *input_file = fopen(argv[1], "r");

    //Check if it's valid
    if (input_file == NULL)
    {
        printf("Could not open file\n");
        return 2;
    } //Declare variables needed

    //Store 512 bytes in array
    unsigned char buffer[512];

    //Track of how many images were generated
    int count_image =0;

    //File pointer to recovered images
    FILE *output_file = NULL;

    //Allocate memory for char filename
    char *filename = malloc(8 * sizeof(char));

    //Read 512 bytes and store on buffer
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //Check if any of them are the beggining of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(count_image > 0)
            {
                fclose(output_file);
            }
            //Create the filename to write the JPEG
            sprintf(filename, "%03i.jpg", count_image);

            //Open the file(output file) to write into it
            output_file = fopen(filename, "w");

            //Counting images found
            count_image++;
        }
        //Check if output was used to a valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(input_file);

    return 0;
}
