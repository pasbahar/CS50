/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include	<ctype.h>
#include "dictionary.h"
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#define SIZE 143091
// struct for our node

int hash_f(char* word);

 typedef struct node
{
    char word[LENGTH];
    struct node *next;
} node;


// global to keep track of size of dictionary
int gSize = 0;

// global array of buckets to hold dictionary
node *array[SIZE];

/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
 // string to hold lowercase  word
    char str[LENGTH + 1];

    // convert string to lowercase to check against out dictionary
    for(int i = 0; i < strlen(word); i++)
    {   
        if(word[i] == '\'')
            str[i] = '\'';
        else if(word[i] >= 'A' && word[i] <= 'Z')
            str[i] = (word[i] - 'A' + 'a');
        else
            str[i] = word[i];
    }
    str[strlen(word)] = '\0';
    // hash of word we're looking for 
    unsigned int index = hash_f(str);
    
    // pointer to current node
    node *bucket = array[index];
    
    // traverse dictionary while next is not null 
    while(bucket->next != NULL)
    {
        if(strcmp(str, bucket->word) == 0)
            return true;
        bucket = bucket->next;
    }
    return false;
}


/*
 * Loads dict into memory.  Returns true if successful else false.
 */
 
bool
load(const char *dict)
{
    // load dictionary so we can read it into memory
    FILE *fp = fopen(dict, "r");
    if(fp == NULL)
    {
        printf("Error loading dictionary!\n");
        return 1;
    }

    // iterate through global array setting pointers up 
    for(int i = 0; i < SIZE; i ++)
    {
        array[i] = malloc(sizeof(node));
        array[i]->next = NULL;
    }

    // get word to add to dictionary
    char key[LENGTH];
   // int c;
    unsigned int index;
    //int j = 0;
    //node *new_node = malloc(sizeof(node));
    // while we have input add it to key
    while((fscanf(fp,"%s",key)) != EOF)
    {
      
        // hash key to get array index where we will have our buckets
        //index = (key[0] - 'a' + 33)%SIZE;
        index=hash_f(key);
        
       // store pointer to array to keep track out our position while we search
        node *current = array[index];
        
        // traverse buckets looking for our key
        while(current->next != NULL)
        {
            if(strcmp(key, current->word) == 0)
                continue; //key is already in Set
            current = current->next;
        }

        // if we don't find our key add a new bucket and put it at the top
        // of our list 
        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, key);
        new_node->next = array[index];
        array[index] = new_node;

        // increment size of dictionary
        gSize++;
    }
    return true;
}


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int
size(void)
{
    // TODO
    return gSize;
    
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    // TODO
    node *bucket, *previous;
    int index = 0;
    while(index < SIZE)
    {
        bucket = array[index];
        while(bucket->next != NULL)
        {
            previous = bucket;
            bucket = bucket->next;
            previous = NULL;
        }
        index++;
    }
    return true;
}

int hash_f(char* word)
{
    unsigned int index=0;
      

        for (int i=0, n=strlen(word); i<n; i++)
        {
            index=(index<<2)^word[i];
        }
        index=(index)%SIZE;
        
    return index;
}/*
