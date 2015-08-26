#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    int k;
    do
    {
    printf("Please enter positive integer number:");
    k = GetInt();
    }       
    while (k<=0);
    
     do
   {
       if (k>26)
        k=k-26;
   }
    while (k>=26);
    char c;
    for (int i=1; i<argc; i++)
    {
        for (int j=0, n=strlen(argv[i]); j<n;j++)
        {
        
        if (isalpha(argv[i][j]))
            {
            if (isalpha(argv[i][j]+k))
               c=(int) argv[i][j]+k;
            else
               c=(int) argv[i][j]+k-26;
            }
        else
            c=(int) argv[i][j];
            
            printf("%c", c);            
               
        }
    printf(" ");
    }
printf("\n");
}


//if (int argv[i][j]+k)
        
        
            //printf("%c\n", argv[i][j]);
            /*for (char i='A'; i<='Z'; i++)
            {
            printf("%i is %c\n", (int) i, i );
            }
            if(s[i]>='a' && s[i]<='z')
            {printf("%c", s[i]-('a'-'A'));}
            
            */
