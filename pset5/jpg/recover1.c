/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
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
    

  
}
