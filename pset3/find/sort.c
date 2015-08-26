#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // TODO: implement an O(n^2) sorting algorithm
    int b;
    int n=GetInt();
    int values[n];
     for (int i=0; i<=n-1; i++)
     values[i]=GetInt();
    // for(int i=0; i<=4; i++) 
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
    
   int d=GetInt();
   int c=(n-1);
   do
   {
   c=c/2;
   
    if (d > values[c])
    for  (int i=0; i<=c; i++)
          values[i]=values[c+i]; 
    if (d==values[c])
    printf("values[%i]=%i\n",c,values[c] );   
   }
   while (d!=values[c] && c>1); 
   if (c<=1 && d!=values[c])
    printf("the number is not found!\n");
}
