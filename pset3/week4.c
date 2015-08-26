#include<cs50.h>
#include<stdio.h>

int main(void)
{
    printf("Say something:");
    string s=Getstring();
    
    printf("Say something:");
    string t= Getstring()
}
//_________________

int naim (void)
{
    char* s=Getstring();
    if(s==NULL)
    {
        return=1;
    }
    for (int i=0, n=strlen(s); i<n;i++)
    {
        printf("$c\n", *(s+i));
    }
}

//___________________
void swap(int* a, int* b);

int main (void)
{
    int x=1;
    int y=2;
    
    swap(&x, &y);
}

