#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
//BYTE isnt automatically a part of the c library, so you need to define it

#define BLOCKSIZE 512
#define BYTESIZE 8
//you want to read 512 blocks of bytes each time, which is why the block size is 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        //if there is more arguments then needed, or there aren't any put into the command line
        printf("Usage: ./recover image\n");
        return 1;
    }
    int n = -1;
    //starts at -1 so it is easier to assign the names
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        //we were unable to open this file
        printf("File not found\n");
        return 1;
    }
    BYTE buffer[BLOCKSIZE];
    FILE *outfile;
    //declares the file "outfile"
    while (fread(buffer, BLOCKSIZE, 1, file))
        //while loop, so the program only runs when files are able to be read, when they arent the loop is exited
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            //looks for the starting of a jpg file (the last line is arthmetic, search it up later and try to understand)
        {
            if (n == -1)
                //checking to see if there has been any other jpeg file
            {
                //now you know it is the first jpeg file
                n = 0;
                char filename [8];
                //so this filename can have a max of 8 bits, numbers (000)
                sprintf(filename, "%03i.jpg", n);
                outfile = fopen(filename, "w");
                if (outfile == NULL)
                {
                    //if file does not open, it quits the program
                    printf("error");
                    return 1;
                }
                fwrite(buffer, BLOCKSIZE, 1, outfile);
            }
            else if (n >= 0)
            {
                //this loop happens if there has already been one jpeg file fournd, but now there is another one found (so the beginning of another jpg file was found)
                n++;
                fclose(outfile);
                char filename [8];
                sprintf(filename, "%03i.jpg", n);
                outfile = fopen(filename, "w");
                if (outfile == NULL)
                {
                    //if file does not open, quits the program
                    printf("error");
                    return 1;
                }
                fwrite(buffer, BLOCKSIZE, 1, outfile);
            }
        }
        else
        {
            if (n >= 0)
            {
                //keep writing in this file, continue
                fwrite(buffer, BLOCKSIZE, 1, outfile);
            }
        }

    }
    fclose(outfile);
    fclose(file);
    return 0;

}
