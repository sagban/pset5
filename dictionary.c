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
#include<ctype.h>

#include "dictionary.h"


// hash table
typedef struct node
{
    char word[46];
    struct node* next;
}node;

//initialized the hash tables
node* hashtables[26] = {NULL};

/**
 * hash function
 */
  unsigned int hashf(const char* val)
  {
      return val[0] % 97;
  }
  

// initilized the counter
int dictsize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //open the dictionary
    FILE* inptr = fopen(dictionary,"r");
    
    //check for valid case
    if(inptr==NULL)
    {
        return false;
    }
    
    // initialized the hash function
    else
    {
        //inilializing a string
        char word[46];
        
        while(fscanf(inptr, "%s\n",word) != EOF)
        {
            dictsize ++;
            node* new_word = malloc(sizeof(node));
            int x = hashf(word);
            if(x>25)
            {
                return false;
            }
            
            strcpy(new_word -> word, word);
            if(hashtables[x] == NULL)
            {
                hashtables[x] = new_word;
                new_word -> next = NULL;
            }
            else
            {
                new_word -> next = hashtables[x];
                hashtables[x] = new_word;
            }
            
           
        }
        fclose(inptr);
        return true;
    }

}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
     char temp[strlen(word)];
     
     
    for(int i = 0; i< strlen(word); i++)
    {
        temp[i] = tolower(word[i]);
    }
    
    temp[strlen(word)]='\0';
    
    node* cursor =  hashtables[hashf(temp)];
    
    while(cursor != NULL)
    {
        //word found in hashtables
        if(strcmp(cursor -> word, temp) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // Returns dictionary size
    return dictsize;
}


/**
 * this function helps in unload dictionary
 * by reccursion
 */
 void del(node* head)
 {
     node* cursor = head;
     if(cursor -> next == NULL)
     {
         free(cursor);
     }
     else
     {
         del(cursor -> next);
     }
     
 }
 

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for(int a=0;a<26;a++)
    {
        del(hashtables[a]);
    }
    return true;
}
