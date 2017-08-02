/**
    Simple program that takes a file as an argument and plays with its bits
    
    J. Bobula - 2017
**/

#include <stdio.h>
#include <stdlib.h>

 int main (int argc, char* argv[])
 {
    //Varables for program
    FILE *myFile;           //File to scan through
    unsigned long len;      //Length of the file
    int *buffer;           //Buffer to hold the bytes of the file
    //Make sure a file path was passed to the program
    if (argc > 1)
    {
        printf("%s\n", argv[1]);
        //Grab the file and open it (readonly)
        myFile = fopen(argv[1], "r");
        if (myFile == NULL)
        {
            printf("Failed to open file\n");
        }
        
        //Get the size of the file
        fseek(myFile, 0, SEEK_END);
        len = (unsigned long)ftell(myFile);
        printf("File is %lu bytes long\n", len);
        
        //Rewind to the beginning of the file
        rewind(myFile);
        
        //Make the buffer big enough to hold the entire file
        buffer = (int *)malloc((len + 1) * sizeof(int));
        
        //Read the file into the buffer
        fread(buffer, sizeof(int), len, myFile);
        
        //Iterate through the file one byte at a time
        for(int i=0; i < len; i++)
        {
            printf("Byte %d is %20x\n", i, buffer[i]); 
        }
        
        //Close the file
        fclose(myFile);
        
    //If no valid path was passed, quit with message
    } else {
        printf("You must pass a valid path to a file\n");
    }
 }
 
