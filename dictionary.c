/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>

#include "dictionary.h"



typedef struct node
{
    char word[46];
    struct node* next;
}node;
/**
 * hash function
 */
  unsigned int hashf(const char* val)
  {
      return val[0] % 97;
  }
  
 

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* cursor;
    cursor = hashtables[hashf(word)];
    while(cursor != NULL)
    {
        if(strcmp(word,cursor -> word))
        {
            return true;
        }
        cursor = cursor -> next;
    }
    
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* inptr = fopen(dictionary,"r");
    if(inptr==NULL)
    {
        return false;
    }
    
    // initialized the hash function
    else
    {
        
        node* new_word; 
        new_word = malloc(sizeof(node));
        node* hashtables[26] = {NULL};
        
        while(fscanf(inptr, "%s", new_word -> word))
        {
            int x = hashf(new_word -> word);
            
            
            if(hashtables[x] == NULL)
            {
                hashtables[x] = malloc(sizeof(node));
                
            }
            
            new_word -> next = hashtables[x];
            while(new_word != NULL)
            {
                new_word = new_word -> next;
            }
            
            
        }
        
        
        return true;
    }

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(const char* dictionary)
{
    // TODO
    int count = 0;
    FILE* inptr = fopen(dictionary,"r");
    node* new = NULL;
     while(fscanf(inptr, "%s", new -> word) != EOF)
     {
         count++;
     }
     fclose(inptr);
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
