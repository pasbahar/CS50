#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
int a[2][2];
int b[4][4];
int x;
int y=0;

   for(int i=0;i<2;i++)
   {
     
     for (int r=0;r<2;r++) 
       {
        y=r+i;
        for(int j=0;j<2;j++)
         {
            
            a[i][j]=5+j+i;
            
                for (int l=0; l<2; l++)
                {
                    x=l+j;
                    b[y][x]=a[i][j];
                    printf("%i ", b[y][x]);
                }
                        
         //   printf("%i ", a[i][j]);
          
   
         }
         printf("\n");
        }
       }
        
   
}





