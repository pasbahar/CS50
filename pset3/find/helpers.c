/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
   int c=(n-1);
   do
   {
   c=c/2;
   
    if (value > values[c])
    for  (int i=0; i<=c; i++)
          values[i]=values[c+i]; 
    if (value==values[c])
    printf("values[%i]=%i\n",c,values[c] );   
   }
   while (value!=values[c] && c>1); 
   if (value<=1 && value!=values[c])
    {
        printf("the number is not found!\n");
        return false;
    }
    else
        return true;
}
    /*int b;
    for (int i=0; i<=n-1; i++)
        {
        if (value==values[i])
            {b=1; 
               // printf()
            
            }         
        }
    if (b==1)
        return true;
    else 
      return false;*/ 
      
    


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    int b;
    do
    {
    b=0;
      for (int i=0; i<=n-2; i++)
      {   
        if (values[i]>values[i+1])
            {
            int tmp=values[i];
            values[i]=values[i+1];
            values[i+1]=tmp;
            b=1;
            }
       }
      // printf("%i\n", b);
    }
    while(b==1);
    for (int i=0; i<=n-1; i++)
    printf("%i\n", values[i]);
}    
    
  











