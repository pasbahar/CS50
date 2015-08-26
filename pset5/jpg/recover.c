/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
 
 /**
 * recover.c
 *
 * Ankit Gupta
 * ankitgupta@college.harvard.edu
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

// declare prototype for the tool that will make an image.
void makeimage(int i, FILE* file, char* buffer, char* title);

int main(int argc, char* argv[])
{
    // make sure the user did not enter any command line arguments.
    if (argc != 1)
    {
        return 0;
    }
    
    // open the file from which we are going to recover jpgs. 
    // check for null pointer if file did not exist.
    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Could not open card.raw");
        return 1;
    }
    
    // declare a buffer of size 512 and allocate space for the title.
    char buffer[512];
    char* title = malloc(sizeof(char) * 7);
    
    // declare and initialize integers that will be used later.
    int elements = 0;
    int i = -1;
    
    do
    {
        // start reading until program reaches the start of a jpg.
        // the numbers correspond to the starting values of a jpg.
        elements = fread(&buffer, sizeof(char), 512, file);
        if (buffer[0] == (char) 255 && buffer[1] == (char) 216 && buffer[2] 
                == (char) 255 && (buffer[3] == (char) 224 || buffer[3] 
                == (char) 225))
        {
            // i will be used for the fielename, and fseek moves back to 
            // the start of the jpg so that the function makeimage can 
            // process the whole jpg.
            i++;
            fseek(file, -512, SEEK_CUR);
            makeimage(i, file, buffer, title);	
        }
    }
    while (elements == 512);
    
    // close the file and free memory.
    fclose(file);
    free(title);
}   

// This function makes the new image when main discovers the start of a jpg.
void makeimage(int i, FILE* file, char* buffer, char* title)
{
    // initialize integers; counter makes sure that the loop doesn't break
    // too early.
    
    int a = 0;
    int counter = 0;
    
    // title the new image and open it, then check for null pointers.
    sprintf(title, "%03d.jpg", i);
    FILE* newimg = fopen(title, "a");
    if (newimg == NULL)
    {
        printf("Could not open newimg");
        return;
    }
    
    // if the start of a new image is not found, then continue to copy 
    // 512 byte at a time.
    do
    {  
        counter++;
        a = fread(buffer, sizeof(char), 512, file);
        if ((counter == 1) || ( (a == 512) && (buffer[0] != (char) 255 || 
                buffer[1] != (char) 216 || buffer[2] != (char) 255 || 
                (buffer[3] != (char) 224 && buffer[3] != (char) 225))))
        {
            fwrite(buffer, sizeof(char), 512, newimg); 
        }
        
        // if the start of a new image is found, break out of the loop.
        else
        {
            break;
        }    
    }
    while (1 == 1);
    
    // move back 512 bytes so that main goes to the start of the image
    fseek(file, -512, SEEK_CUR);
    
    // close the image file.
    fclose(newimg);
}
       
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: .recover file\n");
        return 1;
    }

    
    // open input file 
    FILE* inptr = fopen(argv[1], "r");
    
    //check the file avaibility
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }
    //define condition of the end of card
    bool not_end=1;
    
    //buffer with 512 bytes
    BYTE buffer[512];
    
    //variable for pictures caunting
    int pictures=0;
    
    //define an empty outfile
    FILE* outfile=NULL;
    //repeat until end of card
    while(not_end)
    {
      for (int i=0; i<512;i++)
        {
            if (feof(inptr)) // is end of card
            {
                fclose(inptr); // close the input file
                not_end=0; //set not_end to false
                
                if (outfile!=NULL)
                fclose(outfile);//close the outfile if it exists
                
                printf("found %d pictures\n", pictures);//print how many pictures are fund
                
                return 0;
            } 
           fread(&buffer[i], sizeof(BYTE), 1, inptr); // copy bytes from input file to buffer
        } 
        // if start of a new jpg
       if((buffer[0]==0xff) && (buffer[1]==0xd8) && (buffer[2]==0xff) && (buffer[3]==0xe0 || buffer[3]==0xe1)) 
            {
            pictures++;
            
            if(outfile!=NULL) 
            fclose(outfile); // if previous image file exists, close the file 
            //define naem for new file
            char name[4]; 
            
            sprintf(name,"%03d.jpg", pictures-1);
            
            outfile = fopen(name,"w");
            
            if (outfile==NULL)
                {
                    printf("Could not write the image.\n");
                    return 1;
                }
            //write from buffer to outfile
            fwrite(&buffer[0],sizeof(BYTE)*512,1,outfile);
            }
            else if(outfile!=NULL) 
                {
                //contunue writing from buffer to outfile
                    fwrite(&buffer[0],sizeof(BYTE)*512,1,outfile);
                }
                
     }
    

  
}*/
