#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{

if (argc!=2)
   {
   printf("Program input accepts a single command-line argument: a keyword\
   composed entirely of alphabetical characters.\n");
      return 1;
    }
string k = argv[1]; 
int e =0;
for (int j=0, n=strlen(k); j<n;j++)
       
        if (!isalpha(k[j]))
            e=1;
                        
        
   if (argc!=2 || (e==1))
   {
   printf("Program input accepts a single command-line argument: a keyword\
   composed entirely of alphabetical characters.\n");
      return 1;
    }
    char c;
    string t;
    t=GetString();
    int p=0;
    int q;
   for (int i=0, n=strlen(t); i<n;i++)
   { 
    if (isupper(k[p]))
       q=(int) (k[p] - 'A');
    if (islower(k[p]))
       q=(int) k[p] - 'a';
    
    if (isalpha(t[i]))
            {
            if (islower(t[i]) && isalpha(t[i]+q))
               c=(int) t[i]+q;
            else if (isupper(t[i]) && isalpha(t[i]+q) && isupper(t[i]+q))
               c=(int) t[i]+q;
            else
               c=(int) t[i]+q-26;
               
            p=p+1;
            }
        else
            c=(int) t[i];
            
    printf("%c", c);
                   
    if (p>strlen(k)-1)
       p=0;

   }
printf("\n");
  
}



