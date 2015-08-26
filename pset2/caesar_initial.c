#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
   if (argc!=2)
   {
   printf("Program input accepts a single command-line argument: a non-negative integer only.\n");
      return 1;
    }
    int k = atoi(argv[1]); 
    
    
     do
   {
       if (k>26)
        k=k-26;
   }
    while (k>=26);
    string t;
    t=GetString();
    char c;

        for (int i=0, n=strlen(t); i<n;i++)
        {
        
        if (isalpha(t[i]))
            {
            if (isalpha(t[i]+k))
               c=(int) t[i]+k;
            else
               c=(int) t[i]+k-26;
            }
        else
            c=(int) t[i];
            
            printf("%c", c);            
               
 
    }
printf("\n");
}



