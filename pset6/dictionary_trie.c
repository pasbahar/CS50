/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include <ctype.h>   

#include "dictionary.h"

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    bool end_word;
    struct node *children[27];
} node;

node* root;


int charNumber(char c);

void deleteTree(node* x);

int count=0;


/*
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
     
    node *level=root;
   // bool a=true;
   
for(int i=0; i<strlen(word);i++)
    {
    if(level->children[charNumber(word[i])]==NULL)
           return false;
       level = level->children[charNumber(word[i])];
    }  
if(level->end_word)
    return true;

return false;
}

/*bool*/
/*check(const char *word)*/
/*{*/
/*    node *ptr = root;*/
/*    for (int i=0;i<strlen(word);i++)*/
/*    {*/
/*        if (ptr->children[charNumber(word[i])] == NULL)*/
/*            return false;*/
/*        ptr = ptr->children[charNumber(word[i])];*/
/*    }*/
/*    if (ptr->end_word)*/
/*        return true;*/
/*    else*/
/*        return false;*/
/*}*/


   //Loads dictionary into memory.  Returns true if successful else false.
bool load(const char* dictionary)
{
    
    // TODO
     // load dictionary so we can read it into memory
    FILE *fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        printf("Error loading dictionary!\n");
        return 1;
    }
root=malloc(sizeof(node));
  
char key[LENGTH+1];
 
 while((fscanf(fp,"%s",key)) != EOF) 
 {   
 node* level=root; 
       for (int i=0; i<strlen(key);i++)
       {
      
        if(level->children[charNumber(key[i])]==NULL)
            {      
              node *new=malloc(sizeof(node));
              level->children[charNumber(key[i])]=new;
            }
        level=level->children[charNumber(key[i])];
        }
        level->end_word=true;
         count++;
   }
 fclose(fp);
    return true;
}

/*bool*/
/*load(const char *dictionary)*/
/*{*/
/*//    char word[LENGTH+1];  // must initialize to zero! Or there will be some weird problem.*/
/*    FILE *fp = fopen(dictionary,"r");*/
/*    if (fp == NULL)*/
/*        return false;*/

/*root=malloc(sizeof(node));*/

/*    while (!feof(fp))*/
/*    {*/
/*        char word[LENGTH+1] = {};*/
/*        fscanf(fp,"%s\n",word); // have to use "%s\n" instead of "%s", or the count will be wrong, don't know why.*/
/*        count++;    */
/*        node *ptr = root;*/
/*        for (int i=0;i<strlen(word);i++)*/
/*        {*/
/*            if (ptr->children[charNumber(word[i])] == NULL)*/
/*            {*/
/*                node *new = malloc(sizeof(node));   */
/*                *new = (node) {false,{NULL}};       // initiallization*/
/*                ptr->children[charNumber(word[i])] = new;*/
/*                ptr = new;*/
/*            }*/
/*            else*/
/*            {*/
/*                ptr = ptr->children[charNumber(word[i])];*/
/*            }*/
/*         }*/
/*         ptr->end_word = true;*/
/*    }*/
/*fclose(fp);           */
/*return true;*/
/*}*/

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    node* level=root;
    deleteTree(level);
    return true;
}

int charNumber(char c)
{
       int num;
    if (c == '\'')
        return 26;
    else if(c >= 'A' && c <= 'Z')
        c += 32;
    num = c - 'a';
    return num;
}

void deleteTree(node* x)
{
    if(x==NULL)
    return;
    for (int i=0; i<27;i++)
    {
    deleteTree(x->children[i]);
    }
    free(x);
    
}


